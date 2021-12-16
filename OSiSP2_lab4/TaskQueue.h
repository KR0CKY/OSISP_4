#pragma once
#include <Windows.h>
#include <vector>
#include <queue>
#include <string>
#include "SortTask.h"


class TaskQueue
{
private:
	CRITICAL_SECTION lock;
	std::queue<SortTask*> tasks;
public:
	TaskQueue();
	void Enqueue(SortTask* task);
	SortTask* Dequeue();
	bool Empty();
	~TaskQueue();
};

