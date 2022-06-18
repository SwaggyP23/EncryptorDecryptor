#include "FileParser.h"

#include <iostream>
#include <sstream>

/*
 * Need to change the way this system works to accept more than one character into the second part of the map 
 */

FileParser::FileParser()
{
}

FileParser& FileParser::Get()
{
	static FileParser s_Instance;
	return s_Instance;
}

void FileParser::parseFile(const std::string& filePath)
{
	CharSize type = CharSize::NONE;
	std::unordered_map<char, char> LowerResult;
	std::unordered_map<char, char> CapitalResult;
	std::stringstream ss[2];
	std::string line;

	m_InputStream.open(filePath);
	
	if (!m_InputStream.is_open())
		CORE_LOG_ERROR("Could not open file");
	else
	{
		while (std::getline(m_InputStream, line))
		{
			if (line.find('#') != std::string::npos)
			{
				if (line.find("Capital") != std::string::npos)
					type = CharSize::Capital;
				else if (line.find("Lower") != std::string::npos)
					type = CharSize::Lower;
			}
			else
				ss[(int)type] << line << '\n';
		}
	}

	while (std::getline(ss[0], line, '\n'))
	{
		CapitalResult[ line[0] ] = line[2];
	}

	while (std::getline(ss[1], line, '\n'))
	{
		LowerResult[line[0]] = line[2];
	}

	m_CapitalLowerMap = { LowerResult, CapitalResult};
}