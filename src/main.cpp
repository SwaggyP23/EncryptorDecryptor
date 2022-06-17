#include "Decryptor.h"
#include "Encryptor.h"
#include "FileParser.h"

#include <iostream>

int main()
{
	reda::Log::Init(); // Initializing the loggin library.

	FileParser::Get().parseFile("res/Key.txt");

	std::unordered_map<char, char> resC = FileParser::Get().getCharMap().capitalMap;
	std::unordered_map<char, char> resL = FileParser::Get().getCharMap().lowerMap;

	LOG_INFO("Upper case unordered_map");
	for (auto&[key, code] : resC)
	{
		std::cout << key << '\t' << code << std::endl;
	}

	LOG_INFO("Lower case unordered_map");
	for (auto&[key, code] : resL)
	{
		std::cout << key << '\t' << code << std::endl;
	}

	std::cin.get();
}