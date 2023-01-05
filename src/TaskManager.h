#pragma once

class TaskManager
{
	friend class Task;

public:
	Task createTask(int max_progress = 100, int current_progress = 0);

private:
	void finish_task(int task_id);

private:

};
