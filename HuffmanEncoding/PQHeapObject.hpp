#pragma once
#include <string>
#include <assert.h>
#include <sstream>
class PQHeapObject
{
private:
	PQHeapObject *Left;
	PQHeapObject *Right;

public:
	PQHeapObject(int aPriority, char aCharacter) : Priority(aPriority), myChar(aCharacter) {}
	int Priority = 0;
	char myChar = '*';
	PQHeapObject(PQHeapObject * aLeft, PQHeapObject * aRight) : Left(aLeft), Right(aRight) {
		Priority = Left->Priority + Right->Priority;
	}




	bool generateEncodeValue(char aChar, std::stringstream& myString)
	{
		if (myChar == aChar)
		{
			return true;
		}
		bool Found = false;
		if (Left)
		{
			if(Left->generateEncodeValue(aChar, myString))
			{
				myString.put('1');
				return true;
			}
		}
		if (Right)
		{
			if (Right->generateEncodeValue(aChar, myString))
			{
				myString.put('0');
				return true;
			}
			else {
				return false;
			}
		}
	}

	void serialize(std::stringstream& myStream)
	{
		myStream.put(myChar);
		if (Left)
		{
			Left->serialize(myStream);
		}
		else {
			myStream.put('\\');
		}
		if (Right)
		{
			Right->serialize(myStream);
		}
		else {
			myStream.put('\\');
		}
	}
};