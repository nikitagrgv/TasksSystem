#include "TaskManager.h"

#include <algorithm>
#include <cassert>

namespace
{
int MAX_TASKS_COUNT = 10000;
}

int TaskManager::createTask(int max_progress, int current_progress)
{
	assert(tasks_.size() < MAX_TASKS_COUNT);

	Task task;
	task.task_id = generate_task_id();
	task.current_progress = current_progress;
	task.max_progress = max_progress;
	task.is_finished = false;

	tasks_.push_back(task);

	return task.task_id;
}

void TaskManager::removeTask(int task_id)
{
	for (int i = 0; i < tasks_.size(); i++)
	{
		if (tasks_[i].task_id == task_id)
			tasks_.erase(tasks_.begin() + i);

		return;
	}
}

bool TaskManager::isTaskExists(int task_id) const
{
	for (const auto &task : tasks_)
	{
		if (task.task_id == task_id)
			return true;
	}

	return false;
}

void TaskManager::finishTask(int task_id)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->is_finished = true;
}

void TaskManager::setCurrentProgress(int task_id, int value)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->current_progress = value;
}

int TaskManager::getCurrentProgress(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->current_progress;
}

void TaskManager::setMaxProgress(int task_id, int max)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->max_progress = max;
}

int TaskManager::getMaxProgress(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->max_progress;
}

int TaskManager::generate_task_id() const
{
	int id = 1;
	while (isTaskExists(id))
		id++;

	return id;
}

TaskManager::Task *TaskManager::get_task_by_id(int id)
{
	for (auto &task : tasks_)
	{
		if (task.task_id == id)
			return &task;
	}

	return nullptr;
}

const TaskManager::Task *TaskManager::get_task_by_id(int id) const
{
	return const_cast<TaskManager*>(this)->get_task_by_id(id);
}

int TaskManager::getTasksCount() const
{
	return tasks_.size();
}

int TaskManager::getTaskId(int index) const
{
	return tasks_[index].task_id;
}
