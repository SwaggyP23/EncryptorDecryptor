#pragma once

#ifndef _STRING_PARSER_
#define _STRING_PARSER_

#include <string>
#include <fstream>
#include <unordered_map>

#include "Log.h"

struct CharMap
{
	std::unordered_map<char, std::string> lowerMap;
	std::unordered_map<char, std::string> capitalMap;
};

class TestingStringParser
{
public:
	static TestingStringParser& Get();

	void parseFile(const std::string& filePath);

	inline CharMap getCharMap() const { return m_CapitalLowerMap; }

private:
	TestingStringParser();

	std::ifstream m_InputStream;
	CharMap m_CapitalLowerMap;

	enum class CharSize
	{
		NONE = -1,
		Capital,
		Lower
	};

};

#endif // !_STRING_PARSER_