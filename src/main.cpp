#include "TasksManager.h"

#include <iostream>

using namespace std;

std::string create_progress_line(int current, int max)
{
	constexpr int line_size = 20;

	string str;
	str.reserve(line_size + 2);

	str += '[';

	int finished_symbols = line_size * current / max;

	for (int i = 0; i < finished_symbols; i++)
		str += '#';
	for (int i = 0; i < line_size - finished_symbols; i++)
		str += ' ';

	str += ']';

	return str;
}

void show_progress(const TasksManager &manager)
{
	system("cls");

	for (int id : manager.getTasksIds())
	{
		cout << manager.getName(id) << ":" << endl;

		const int current = manager.getCurrentProgress(id);
		const int max = manager.getMaxProgress(id);

		cout << current << "/" << max << endl;
		cout << create_progress_line(current, max).c_str();
		if (manager.isTaskFinished(id))
			cout << " FINISHED";
		cout << endl << endl;
	}
}

int main()
{
	TasksManager task_manager;

	// create tasks
	int task1 = task_manager.createTask();
	task_manager.setName(task1, "Task 1");

	int task2 = task_manager.createTask();
	task_manager.setName(task2, "Task 2");
	task_manager.setMaxProgress(task2, 300);

	int task3 = task_manager.createTask();
	task_manager.setName(task3, "Task 3");

	// wait for all tasks to finish
	while (!task_manager.isAllTasksFinished())
	{
		{
			int current = task_manager.getCurrentProgress(task1);
			if (current >= task_manager.getMaxProgress(task1))
				task_manager.finishTask(task1);
			else
				task_manager.setCurrentProgress(task1, current + 1);
		}

		{
			int current = task_manager.getCurrentProgress(task2);
			if (current >= task_manager.getMaxProgress(task2))
				task_manager.finishTask(task2);
			else
				task_manager.setCurrentProgress(task2, current + 2);
		}

		{
			int current = task_manager.getCurrentProgress(task3);
			if (current >= task_manager.getMaxProgress(task3))
				task_manager.finishTask(task3);
			else
				task_manager.setCurrentProgress(task3, current + 3);
		}

		show_progress(task_manager);
	}

	system("pause");

	return 0;
}
