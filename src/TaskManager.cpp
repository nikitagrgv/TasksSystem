#include "TaskManager.h"

#include "Task.h"

Task TaskManager::createTask(int max_progress, int current_progress)
{
	static int g = 1;

	return {g++, *this};
}

void TaskManager::finish_task(int task_id)
{

}
