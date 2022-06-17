#pragma once

#ifndef _FILE_PARSER_
#define _FILE_PARSER_

#include <string>
#include <fstream>
#include <map>

#include "Log.h"

struct CharMapping
{
	std::map<char, char> lowerMap;
	std::map<char, char> capitalMap;
};

class FileParser
{
	static FileParser& Get();
	CharMapping parseFile(const std::string& filePath);

private:
	FileParser();
	std::ifstream m_InputStream;

	enum class CharSize
	{
		NONE = 0,
		Capital,
		Lower
	};
};

#endif // _FILE_PARSER_