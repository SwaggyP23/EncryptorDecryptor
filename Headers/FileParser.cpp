#include "FileParser.h"

#include <iostream>
#include <sstream>

FileParser& FileParser::Get()
{
	static FileParser instance;
	return instance;
}

CharMapping FileParser::parseFile(const std::string& filePath)
{
	CharSize type = CharSize::NONE;
	std::map<char, char> LowerResult;
	std::map<char, char> CapitalResult;
	std::string line;

	m_InputStream.open(filePath);
	
	if (!m_InputStream.is_open())
		LOG_ERROR("Could not open file");
	else
	{
		while (std::getline(m_InputStream, line))
		{
			if (line.find("Capital"))
				type = CharSize::Capital;
			else if (line.find("Lower"))
				type = CharSize::Lower;
		}
	}

}

FileParser::FileParser()
{
}