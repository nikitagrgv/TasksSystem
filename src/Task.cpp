#include "Task.h"

#include "TaskManager.h"

#include <utility>
#include <iostream>

Task::Task(int task_id, TaskManager &task_manager)
	: task_manager_(&task_manager)
	, task_id_(task_id)
{}

Task::~Task()
{
	std::cout << "destruct task " << task_id_ << ". valid: " << isValid() << std::endl;

	if (!isValid())
		return;

	task_manager_->finish_task(task_id_);
}

Task::Task(Task &&other) noexcept
	: task_manager_(nullptr)
	, task_id_(-1)
{
	swap(other);
}

Task &Task::operator=(Task &&other) noexcept
{
	swap(other);
	return *this;
}

bool Task::isValid()
{
	return task_manager_ != nullptr && task_id_ != -1;
}

void Task::swap(Task &other)
{
	std::swap(this->task_manager_, other.task_manager_);
	std::swap(this->task_id_, other.task_id_);
}
