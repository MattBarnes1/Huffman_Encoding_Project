
#ifndef PriorityQueue_HPP
#define PriorityQueue_HPP

#include "PriorityQueue_LL.hpp"
#include <iostream>

template<typename T>
class PriorityQueue
{
private:
	PriorityQueue_LL<T> *root = 0;

public:
	PriorityQueue<T>();
	~PriorityQueue<T>();
	void insert_with_priority(T theData, int Priority);
	PriorityQueue_LL<T> *pop_element();
	void insert_without_priority(PriorityQueue_LL<T> *newNode);
	void printQueue();


};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
}




template<typename T>
void PriorityQueue<T>::insert_with_priority(T theData, int Priority)
{
	if (root == 0)
	{
		root = new PriorityQueue_LL<T>(theData, Priority);
		return;
	}
	PriorityQueue_LL<T> *Ptr;
	PriorityQueue_LL<T> *Parent;
	for (Ptr = root; Ptr != 0; Ptr = Ptr->nxt)
	{
		if (Ptr->nxt != 0)
		{
			if (Ptr->Priority <= Priority || Ptr->nxt->Priority > Priority)
			{
				PriorityQueue_LL<T> *Temp = Ptr->nxt;
				Ptr->nxt = new PriorityQueue_LL<T>(theData, Priority);
				Ptr->nxt->nxt = Temp;
				break;
			}
			else if (Ptr == root && Ptr->Priority > Priority)
			{
				PriorityQueue_LL<T> *Temp = root;
				root = new PriorityQueue_LL<T>(theData, Priority);
				root->nxt = Temp;
				break;
			}
		}
		else
		{
			Ptr->nxt = new PriorityQueue_LL<T>(theData, Priority);
			break;
		}
	}
}

template<typename T>
PriorityQueue_LL<T> *PriorityQueue<T>::pop_element()
{
	if (root)
	{
		PriorityQueue_LL<T> *myRet = root;
		root = root->nxt;
		myRet->nxt = 0;
		return myRet;
	}
	else {
		return 0;
	}
}






template<typename T>
void PriorityQueue<T>::insert_without_priority(PriorityQueue_LL<T>* newNode)
{
	if (root == 0)
	{
		root = newNode;
		return;
	}
	PriorityQueue_LL<T> *Ptr;
	PriorityQueue_LL<T> *Parent;
	for (Ptr = root; Ptr != 0; Ptr = Ptr->nxt)
	{
		if (Ptr->nxt != 0)
		{
			if (Ptr->Priority <= newNode->Priority || Ptr->nxt->Priority > newNode->Priority)
			{
				PriorityQueue_LL<T> *Temp = Ptr->nxt;
				Ptr->nxt = newNode;
				Ptr->nxt->nxt = Temp;
				break;
			}
			else if(Ptr == root && Ptr->Priority > newNode->Priority)
			{
				PriorityQueue_LL<T> *Temp = root;
				root = newNode;
				newNode->nxt = Temp;
				break;
			}
		}
		else
		{
			Ptr->nxt = newNode;
			break;
		}
	}
}

template<typename T>
inline void PriorityQueue<T>::printQueue()
{
	PriorityQueue_LL<T> *Ptr;
	for (Ptr = root; Ptr != 0; Ptr = Ptr->nxt)
	{
		if (Ptr->Data != 0)
		{
			std::cout << "[" << Ptr->Data << ":" << Ptr->Priority << "]";
		}
		else {

			std::cout << "( " << Ptr->Priority << ":" ;

			if (Ptr->rightNode)
			{
				std::stringstream myStream;
				Ptr->rightNode->serialize(myStream);
				std::cout << myStream.str();
			}

			if (Ptr->leftNode)
			{
				std::stringstream myStream;
				Ptr->leftNode->serialize(myStream);
				std::cout << myStream.str();
			}
			std::cout << ")";
		}
	}


}
#endif