#include "TasksManager.h"

#include <algorithm>
#include <cassert>

namespace
{
int MAX_TASKS_COUNT = 10000;
}

int TasksManager::createTask()
{
	assert(tasks_.size() < MAX_TASKS_COUNT);

	Task task;
	task.task_id = generate_task_id();
	tasks_.push_back(task);

	return task.task_id;
}

void TasksManager::removeTask(int task_id)
{
	for (int i = 0; i < tasks_.size(); i++)
	{
		if (tasks_[i].task_id == task_id)
			tasks_.erase(tasks_.begin() + i);

		return;
	}
}

bool TasksManager::isTaskExists(int task_id) const
{
	for (const auto &task : tasks_)
	{
		if (task.task_id == task_id)
			return true;
	}

	return false;
}

bool TasksManager::isAllTasksFinished() const
{
	for (const auto &task : tasks_)
	{
		if (!task.is_finished)
			return false;
	}

	return true;
}

void TasksManager::finishTask(int task_id)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->is_finished = true;
}

bool TasksManager::isTaskFinished(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->is_finished;
}

void TasksManager::setCurrentProgress(int task_id, int value)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->current_progress = value;
}

int TasksManager::getCurrentProgress(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->current_progress;
}

void TasksManager::setMaxProgress(int task_id, int max)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->max_progress = max;
}

int TasksManager::getMaxProgress(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->max_progress;
}

int TasksManager::generate_task_id() const
{
	int id = 1;
	while (isTaskExists(id))
		id++;

	return id;
}

TasksManager::Task *TasksManager::get_task_by_id(int id)
{
	for (auto &task : tasks_)
	{
		if (task.task_id == id)
			return &task;
	}

	return nullptr;
}

const TasksManager::Task *TasksManager::get_task_by_id(int id) const
{
	return const_cast<TasksManager *>(this)->get_task_by_id(id);
}

int TasksManager::getTasksCount() const
{
	return tasks_.size();
}

int TasksManager::getTaskId(int index) const
{
	return tasks_[index].task_id;
}

std::vector<int> TasksManager::getTasksIds() const
{
	std::vector<int> ids;
	for (const auto &task: tasks_)
		ids.push_back(task.task_id);
	
	return ids;
}

void TasksManager::setName(int task_id, const char *name)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->name = name;
}

const char *TasksManager::getName(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->name.c_str();
}

void TasksManager::setInfo(int task_id, const char *info)
{
	assert(isTaskExists(task_id));

	get_task_by_id(task_id)->info = info;
}

const char *TasksManager::getInfo(int task_id) const
{
	assert(isTaskExists(task_id));

	return get_task_by_id(task_id)->info.c_str();
}
