#include "Decryptor.h"
#include "FileParser.h"

std::unordered_map<char, char> Decryptor::DcapCode;
std::unordered_map<char, char> Decryptor::DlowCode;

Decryptor::Decryptor()
{
}

Decryptor& Decryptor::Get()
{
	static Decryptor s_Instance;
	return s_Instance;
}

void Decryptor::Init(const std::string& filePath)
{
	if(FileParser::Get().getCharMap().capitalMap.empty() && FileParser::Get().getCharMap().lowerMap.empty())
		FileParser::Get().parseFile(filePath);

	DcapCode = FileParser::Get().getCharMap().capitalMap;
	DlowCode = FileParser::Get().getCharMap().lowerMap;
}

std::string Decryptor::DecryptMessage(const std::string& message) const
{
	std::string DecryptedResult;

	for (int i = 0; i < message.size(); i++)
	{
		char temp = message[i];
		if (DcapCode.contains(temp))
		{
			DecryptedResult.push_back(DcapCode.at(temp));

			// This is one way to do things is to use iterators, but i already checked if the map contains `temp` therefore,
			// no need to use find again which is in log time worst time complexity. Using the at function will not throw
			// since i am sure that the temp value exists in this if statement since it is already checked in the condition
			//std::unordered_map<char, char>::const_iterator it = capCode.find(temp);
			//encryptResult.push_back(it->second);
		}
		else if (DlowCode.contains(temp))
		{
			DecryptedResult.push_back(DlowCode.at(temp));

			// Same comment as above
			//std::unordered_map<char, char>::const_iterator it = lowCode.find(temp);
			//encryptResult.push_back(it->second);
		}
	}

	return DecryptedResult;
}