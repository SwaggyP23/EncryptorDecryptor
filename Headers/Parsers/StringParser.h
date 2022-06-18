#pragma once

/*
 * This class API is not meant to be used by the user however it could be used for debuggin purposes, it is meant to be used
 * by the Encryptor class to automate the file parsing work.
 * This parser parses all the character of the code and not just the first one, thus enabling us  to have code of multiple
 * characters.
 */

#ifndef _STRING_PARSER_
#define _STRING_PARSER_

#include <string>
#include <fstream>
#include <unordered_map>

#include "Log.h"

class StringParser
{
public:
	static StringParser& Get();

	void parseFile(const std::string& filePath);

	inline std::unordered_map<char, std::string> getCapMap() const { return m_CapitalMap; }
	inline std::unordered_map<char, std::string> getLowMap() const { return m_LowerMap; }
	inline std::unordered_map<char, std::string> getAscMap() const { return m_AscMap; }

private:
	StringParser();

	std::ifstream m_InputStream;
	static std::unordered_map<char, std::string> m_LowerMap;
	static std::unordered_map<char, std::string> m_CapitalMap;
	static std::unordered_map<char, std::string> m_AscMap;

	enum class CharSize
	{
		NONE = -1,
		Capital,
		Lower,
		ASCII
	};

};

#endif // !_STRING_PARSER_