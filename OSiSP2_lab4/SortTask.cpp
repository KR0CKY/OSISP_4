#include "SortTask.h"

SortTask::SortTask(void(*func)(void*), void* params)
{
	this->func = func;
	this->params = params;
}

