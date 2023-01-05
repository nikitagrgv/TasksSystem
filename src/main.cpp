#include <iostream>

#include "TaskManager.h"
#include "Task.h"

#include <iostream>
#include <memory>

int main()
{
	{
		TaskManager task_manager;

		auto t1 = task_manager.createTask();
		auto t2 = task_manager.createTask();

		t2 = task_manager.createTask();
	}

	std::cout << "end\n";

	return 0;
}
