#include "StringParser.h"

#include <iostream>
#include <sstream>

std::unordered_map<char, std::string> StringParser::m_LowerMap;
std::unordered_map<char, std::string> StringParser::m_CapitalMap;
std::unordered_map<char, std::string> StringParser::m_AscMap;

StringParser::StringParser()
{
}

StringParser& StringParser::Get()
{
	static StringParser s_Instance;
	return s_Instance;
}

void StringParser::parseFile(const std::string& filePath)
{
	CharSize type = CharSize::NONE;

	std::unordered_map<char, std::string> LowerResult;
	std::unordered_map<char, std::string> CapitalResult;
	std::unordered_map<char, std::string> ASCIIResult;

	std::stringstream ss[3];
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
				else if (line.find("ASCII") != std::string::npos)
					type = CharSize::ASCII;
			}
			else
				ss[(int)type] << line << '\n';
		}
	}

	while (std::getline(ss[0], line, '\n'))
	{
		std::string temp(line.begin() + 2, line.end());
		//LOG_INFO("{0}", temp);
		CapitalResult[line[0]] = temp;
	}

	while (std::getline(ss[1], line, '\n'))
	{
		std::string temp(line.begin() + 2, line.end());
		//LOG_INFO("{0}", temp);
		LowerResult[line[0]] = temp;
	}

	while (std::getline(ss[2], line, '\n'))
	{
		std::string temp(line.begin() + 2, line.end());
		//LOG_INFO("{0}", temp);
		ASCIIResult[line[0]] = temp;
	}

	m_CapitalMap = CapitalResult;
	m_LowerMap = LowerResult;
	m_AscMap = ASCIIResult;
}