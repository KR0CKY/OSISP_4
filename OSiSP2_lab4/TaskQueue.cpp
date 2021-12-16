#include <Windows.h>
#include "TaskQueue.h"

TaskQueue::TaskQueue()
{
	InitializeCriticalSectionAndSpinCount(&(this->lock), 0x00000400);
}

void TaskQueue::Enqueue(SortTask* task)
{	
	EnterCriticalSection(&lock);
	this->tasks.push(task);
	LeaveCriticalSection(&lock);
}

SortTask* TaskQueue::Dequeue()
{
	while (tasks.empty()) {}
	EnterCriticalSection(&lock);
	SortTask *res = this->tasks.front();
	tasks.pop();
	LeaveCriticalSection(&lock);
	return res;
}

bool TaskQueue::Empty()
{
	return tasks.empty();
}

TaskQueue::~TaskQueue()
{
	while (!this->Empty())
	{
		this->Dequeue();
	}

	DeleteCriticalSection(&(this->lock));
}