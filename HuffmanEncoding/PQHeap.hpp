#pragma once
#include <vector>
#include <assert.h>
#include "PQHeapObject.hpp"
#include <iostream>
class PQHeap
{
private:
	std::vector<PQHeapObject *> priorityQueue;
	PQHeapObject * leftNode(int index);
	PQHeapObject * rightNode(int index);
	PQHeapObject * parentNode(int index);
	void sendDown(int index);
	void sendUp(int index);
	int PQHeap::leftNodeIndex(int index);
	int PQHeap::rightNodeIndex(int i);
	int PQHeap::parentNodeIndex(int index);


public:
	bool empty();
	void push(PQHeapObject *anObject);
	PQHeapObject *pop();
	void printQueue();

};

inline bool PQHeap::empty()
{
	return (priorityQueue.size() == 0);
}

inline void PQHeap::push(PQHeapObject * anObject)
{
	priorityQueue.push_back(anObject);
	int index = priorityQueue.size() - 1;
	sendUp(index);
}

PQHeapObject *PQHeap::pop()
{
	if (empty())
	{
		return 0;
	}
	PQHeapObject * i = priorityQueue[0];
	priorityQueue[0] = priorityQueue.back();
	priorityQueue.pop_back();
	sendDown(0);
	return i;
}

inline void PQHeap::printQueue()
{
	for (int i = 0; i < priorityQueue.size(); i++)
	{
		if (priorityQueue.at(i)->myChar != 0)
		{
			std::cout << "[char: " << priorityQueue.at(i)->myChar << " priority: " << priorityQueue.at(i)->Priority << "]" << std::endl << std::endl;
		}
		else {
			std::cout << "[char: " << "*" << " priority: " << priorityQueue.at(i)->Priority << "]" << std::endl << std::endl;
		}
	}


}

PQHeapObject * PQHeap::parentNode(int index)
{
	assert(index > 0);
	int indexVal = (index - 1) / 2;
	return priorityQueue[indexVal];
}
inline void PQHeap::sendDown(int index)
{
	int left = leftNodeIndex(index);
	int right = rightNodeIndex(index);

	int smallest = index;
	if (left < priorityQueue.size() && priorityQueue[left]->Priority < priorityQueue[smallest]->Priority)
		smallest = left;

	if (right < priorityQueue.size() && priorityQueue[right]->Priority < priorityQueue[smallest]->Priority)
		smallest = right;

	if (smallest != index) {
		std::swap(priorityQueue[index], priorityQueue[smallest]);
		sendDown(smallest);
	}



}
inline void PQHeap::sendUp(int index)
{
	if (index != 0)
	{
		int Parent = parentNodeIndex(index);
		if (priorityQueue[Parent]->Priority > priorityQueue[index]->Priority)
		{
			// swap the two if heap property is violated
			std::swap(priorityQueue[index], priorityQueue[Parent]);
			sendUp(Parent);
		}
	}
}

int PQHeap::leftNodeIndex(int index)
{
	return (index - 1) / 2;
}

int PQHeap::rightNodeIndex(int i)
{
	return (2 * i + 2);
}

int PQHeap::parentNodeIndex(int index)
{
	assert(index > 0);
	return  (index - 1) / 2;
}

PQHeapObject * PQHeap::leftNode(int index)
{
	int indexVal = (index - 1) / 2;
	return priorityQueue[indexVal];
}

PQHeapObject * PQHeap::rightNode(int i)
{
	int indexVal = (2 * i + 2);
	return priorityQueue[indexVal];
}
