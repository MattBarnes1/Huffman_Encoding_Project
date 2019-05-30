#pragma once
template<typename T>
class<typename T> HeapObject
{
	T myData;
	int myPriority;
public:
	HeapObject(T Data, int priority) : myData(Data), myPriority(priority) {};
	HeapObject(int amount) : myData(Data), myPriority(amount) {};
};