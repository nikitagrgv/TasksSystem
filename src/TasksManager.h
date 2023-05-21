#pragma once

#include <vector>
#include <string>

class TasksManager
{
public:
	int createTask();
	void removeTask(int task_id);

	bool isTaskExists(int task_id) const;

	int getTasksCount() const;
	int getTaskId(int index) const;
	std::vector<int> getTasksIds() const;

	void finishTask(int task_id);
	bool isTaskFinished(int task_id) const;

	bool isAllTasksFinished() const;

	void setCurrentProgress(int task_id, int value);
	int getCurrentProgress(int task_id) const;

	void setMaxProgress(int task_id, int max);
	int getMaxProgress(int task_id) const;

	void setName(int task_id, const char *name);
	const char *getName(int task_id) const;

	void setInfo(int task_id, const char *info);
	const char *getInfo(int task_id) const;

private:
	struct Task
	{
		Task() = default;

		std::string name;
		std::string info;
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
