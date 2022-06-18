#pragma once

/*
 * This class API is not meant to be used by the user however it could be used for debuggin purposes, it is meant to be used
 * by the Encryptor class to automate the file parsing work.
 * This also was a first trial on parsing, and only parses the first character of the code not the whole thing.
 */

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

	inline CharMap getCharMap() const { return m_CapitalLowerMap; }

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