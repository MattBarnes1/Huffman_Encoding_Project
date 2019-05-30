// HuffmanEncoding.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Huffman.hpp"
#include <iostream>
#include <queue>
int main()
{

	std::priority_queue<int, std::vector<int>> myStuff;

	std::string c;
	while(std::cin >> c)
	{ 
		if (c.at(0) == 'q' && c.length() == 1)
		{
			break;
		}
		Huffman myHuffman;
		myHuffman.build_tree("MISSISSIPPI");
		std::cout << "Tree:" << myHuffman.serialize() << std::endl;
		std::cout << "String:" << myHuffman.encode("MISSISSIPPI") << std::endl;
	}
	/*myHuffman.build_tree("Eerie eyes seen near lake.");
	std::cout << myHuffman.serialize();
	std::cout << myHuffman.encode("Eerie eyes seen near lake.");
	while (true);*/
    return 0;
}

