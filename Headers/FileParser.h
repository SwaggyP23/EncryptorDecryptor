#pragma once

#ifndef _FILE_PARSER_
#define _FILE_PARSER_

#include <string>
#include <fstream>
#include <unordered_map>

#include "Log.h"

struct CharMap
{
	std::unordered_map<char, char> lowerMap;
	std::unordered_map<char, char> capitalMap;
};

class FileParser
{
public:
	static FileParser& Get();
	void parseFile(const std::string& filePath);
	CharMap getCharMap() const;


private:
	FileParser();
	std::ifstream m_InputStream;
	CharMap m_CapitalLowerMap;

	enum class CharSize
	{
		NONE = -1,
		Capital,
		Lower
	};
};

#endif // _FILE_PARSER_