#pragma once

#include <vector>

class TaskManager
{
public:
	int createTask(int max_progress = 100, int current_progress = 0);
	void removeTask(int task_id);

	bool isTaskExists(int task_id) const;

	int getTasksCount() const;
	int getTaskId(int index) const;

	void finishTask(int task_id);

	void setCurrentProgress(int task_id, int value);
	int getCurrentProgress(int task_id) const;

	void setMaxProgress(int task_id, int max);
	int getMaxProgress(int task_id) const;

private:
	struct Task
	{
		int task_id{-1};
		int current_progress{0};
		int max_progress{100};
		bool is_finished{false};
	};

private:
	int generate_task_id() const;

	Task *get_task_by_id(int id);
	const Task *get_task_by_id(int id) const;

private:
	std::vector<Task> tasks_;
};
