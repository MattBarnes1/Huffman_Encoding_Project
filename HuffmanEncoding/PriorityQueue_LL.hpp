#ifndef PriorityQueue_LL_HPP

#define PriorityQueue_LL_HPP

#include <string>
#include <sstream>

template <typename T>
class PriorityQueue_LL
{

public:
	T Data;
	int Priority;
	PriorityQueue_LL<T> *nxt = 0;
	PriorityQueue_LL<T> *leftNode = 0;
	PriorityQueue_LL<T> *rightNode = 0;
	bool hasData = false;

	PriorityQueue_LL<T>(T newData, int aPriority) : Data(newData), Priority(aPriority), hasData(true){};
	PriorityQueue_LL<T>(PriorityQueue_LL<T>* Node1, PriorityQueue_LL<T>* Node2)
	{

			leftNode = Node1;
			rightNode = Node2;
		
		this->Priority = Node1->Priority + Node2->Priority;
	};

	~PriorityQueue_LL<T>()
	{
		if (nxt)
		{
			nxt->~PriorityQueue_LL();
		}
		if (leftNode)
		{
			leftNode->~PriorityQueue_LL();
		}
		else if (rightNode)
		{
			rightNode->~PriorityQueue_LL();
		}
	};

	bool generateEncodeValue(char SearchString, std::stringstream &Value)
	{
		bool found = false;
		if (hasData)
		{
			if (Data == SearchString)
			{
				return true;
			}
		}
		if (leftNode != 0)
		{
			if (leftNode->generateEncodeValue(SearchString, Value))
			{
				int I = 0;
				Value.put('0');
				return true;
			}
			else {
				//Value.str(Original);
				int i = 0;
			}

		}
		if (rightNode != 0)
		{

			//std::string Original = Value.str();
			if (rightNode->generateEncodeValue(SearchString, Value))
			{
				int I = 0;
				Value.put('1');
				return true;
			}
			else {
			//	Value.str(Original);
				int i = 0;
			}
			/*else {
				std::cout << "Restoring String: " << saveIt;
				*Value = new std::stringstream(saveIt);
				std::string mystr = (*Value)->str();
				std::cout << "New String: " << mystr;
			}*/
		}
			
		return false;
		
	}




	void PriorityQueue_LL<T>::serialize(std::stringstream &myStream)
	{
		if (Data != 0)
		{

			myStream.put(Data);
		}
		else {
			myStream.put('*');
		}

		if (leftNode != 0)
		{
			leftNode->serialize(myStream);
		}
		else {
			myStream.put('/');
		}
		if (rightNode != 0)
		{
			rightNode->serialize(myStream);
		}
		else {
			myStream.put('/');
		}

		
	
	}



	
};

#endif
