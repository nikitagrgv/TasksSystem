#pragma once

class TaskManager;

class Task final
{
	friend class TaskManager;

private:
	Task(int task_id, TaskManager &task_manager);

public:
	~Task();

	Task(const Task& other) = delete;
	Task &operator=(const Task &other) = delete;

	Task(Task &&other) noexcept;
	Task &operator=(Task &&other) noexcept;

	bool isValid();

	void setCurrentProgress(int value);
	int getCurrentProgress() const;

	void setMaxProgress(int max);
	int getMaxProgress() const;

	void swap(Task &other);

private:
	TaskManager *task_manager_{nullptr};
	int task_id_{-1};
};
