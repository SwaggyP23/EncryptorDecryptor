#include "TestingStringParser.h"

#include <iostream>
#include <sstream>

TestingStringParser::TestingStringParser()
{
}

TestingStringParser& TestingStringParser::Get()
{
	static TestingStringParser s_Instance;
	return s_Instance;
}

void TestingStringParser::parseFile(const std::string& filePath)
{
	CharSize type = CharSize::NONE;
	std::unordered_map<char, std::string> LowerResult;
	std::unordered_map<char, std::string> CapitalResult;
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
		std::string temp(line.begin() + 2, line.end());
		LOG_INFO("{0}", temp);
		CapitalResult[line[0]] = temp;
	}

	while (std::getline(ss[1], line, '\n'))
	{
		std::string temp(line.begin() + 2, line.end());
		LOG_INFO("{0}", temp);
		LowerResult[line[0]] = temp;
	}

	m_CapitalLowerMap.capitalMap = CapitalResult;
	m_CapitalLowerMap.lowerMap = LowerResult;
}