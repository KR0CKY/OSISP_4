#pragma once

#include <Windows.h>
#include <vector>
#include "TaskQueue.h"

class ThreadProcessor
{
private:
	TaskQueue *queue;
	static DWORD WINAPI ProcessTask(void* vqueue);
	
public:
	ThreadProcessor(TaskQueue *queue);
	void ExecuteTasks(int threadCount);
};

