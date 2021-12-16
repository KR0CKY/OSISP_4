#pragma once
class SortTask
{
public:
	void* params;
	void (*func)(void*);

	SortTask(void(*func)(void*), void* params);
};