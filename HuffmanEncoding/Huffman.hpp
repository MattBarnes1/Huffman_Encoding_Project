
#ifndef HUFF_HPP

#define HUFF_HPP
//1. A default constructor. 
//2. A destructor — memory leaks will cost you points 
//3. A build_tree function that takes a string and creates a huﬀman coding tree from it. 
//4. An encode function that takes a string and uses the tree created with build_tree to encode the message.This function returns a string representation of the encoded binary. 
//5. A serialize function that returns a string representing the huﬀman tree in a serialized manner.

#include "PQHeap.hpp"
#include "PQHeapObject.hpp"
#include <string>
#include <sstream>
#include <assert.h>
#include <queue>
#include <functional>
#include <iostream>
class Huffman
{
public:
	Huffman() {

	};
	~Huffman() {
		delete WhyGodWhy;
		delete myNewTree;
	};
	void build_tree(std::string aString);
	std::string encode(std::string aString);
	std::string serialize();

	
private:
	
	PQHeapObject *myNewTree;
	PQHeap myQueue;
	std::string findUniqueCharsInString(std::string aString);
	int calculateFrequency(char aChar, std::string aString);
	std::string encodingPatterns(char aChar);
	std::string PatternLookup;
	std::string **WhyGodWhy;
	std::string *lookupValue(char aChar);
};




//5.71
void Huffman::build_tree(std::string aString)
{
	PatternLookup = findUniqueCharsInString(aString);
	WhyGodWhy = new std::string*[PatternLookup.length()+1];
	WhyGodWhy[PatternLookup.length()] = 0;
	

	for (std::string::iterator finishedIt = PatternLookup.begin(); finishedIt != PatternLookup.end(); ++finishedIt)
	{
		std::cout << "Before:" << std::endl;
		myQueue.printQueue();
		std::cout << std::endl;
		myQueue.push(new PQHeapObject(calculateFrequency(*finishedIt, aString), *finishedIt));
		std::cout << "After:" << std::endl;
		myQueue.printQueue();
		std::cout << std::endl;
	}


	std::cout << "Start: " << std::endl;
	myQueue.printQueue();
	std::cout << std::endl;
	std::cout << std::endl;
	PQHeapObject *Node1;
	PQHeapObject *Node2;
	while ((Node1 = myQueue.pop()) != 0 && (((Node2 = myQueue.pop())) != 0))
	{
		std::cout << "Before:" << std::endl;
		myQueue.printQueue();
		std::cout << std::endl;
		//std::stringstream N1;
		//std::stringstream N2;
		//Node1->serialize(N1);
		//Node2->serialize(N2);
		//std::cout << "TAKEN: [" << N1.str() << "]" << "[" << N2.str() << "]" << std::endl;
		//std::cout << std::endl;
		//std::cout << std::endl;
		PQHeapObject *Combined = new PQHeapObject(Node1, Node2);
		std::cout << "After:" << std::endl;
		myQueue.push(Combined);
		myQueue.printQueue();
		std::cout << std::endl;
		std::cout << std::endl; //0- left 1 -right
	}
	

	myNewTree = Node1;


	
	
	std::cout << std::endl << std::endl;
	for (int i = 0; i < PatternLookup.length(); i++)
	{
		std::string *mySTD = new std::string(Huffman::encodingPatterns(PatternLookup.at(i)));
		//std::reverse(mySTD->begin(), mySTD->end());
		WhyGodWhy[i] = mySTD;
		std::cout << PatternLookup.at(i) << " : " << *(WhyGodWhy[i]) << std::endl << std::endl;
	}

}



std::string Huffman::serialize()
{
	std::stringstream myStream;
	myNewTree->serialize(myStream);
	return myStream.str();
}

std::string Huffman::findUniqueCharsInString(std::string aString)
{
	std::stringstream myCharacters;

	for (std::string::iterator aChar = aString.begin(); aChar != aString.end(); ++aChar)
	{
		std::string s = myCharacters.str();
		if (s.find(*aChar, 0) == std::string::npos)
		{
			myCharacters.put(*aChar);
		}
	}
	std::string s = myCharacters.str();
	return s;
}

int Huffman::calculateFrequency(char myUniqueChars, std::string aString)
{
	int charCount = 0;
	for (std::string::iterator finishedIt = aString.begin(); finishedIt != aString.end(); ++finishedIt)
	{
		if (myUniqueChars == *finishedIt)
		{
			charCount++;
		}
	}

	return charCount;
}

std::string Huffman::encodingPatterns(char aChar)
{
	std::stringstream myStream;
	myNewTree->generateEncodeValue(aChar, myStream);
	return myStream.str();
}

std::string *Huffman::lookupValue(char aChar)
{
	for (int i = 0; i < PatternLookup.length(); i++)
	{
		if (PatternLookup.at(i) == aChar)
		{
			return WhyGodWhy[i];
		}
	}
}


std::string Huffman::encode(std::string aString)
{
	int totalSize = 0;
	std::string HuffmanReturn("");
	for (int i =  0; i < aString.length(); i++)
	{
		std::string HuffmanReturnVal = HuffmanReturn + *lookupValue(aString.at(i));
		HuffmanReturn = HuffmanReturnVal;
	}
	return HuffmanReturn;
}
#endif
