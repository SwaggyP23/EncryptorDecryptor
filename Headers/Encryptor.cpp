#include "Encryptor.h"
#include "StringParser.h"

std::unordered_map<char, std::string> Encryptor::EcapCode;
std::unordered_map<char, std::string> Encryptor::ElowCode;

Encryptor::Encryptor()
{
}

Encryptor& Encryptor::Get()
{
	static Encryptor s_Instance;
	return s_Instance;
}

void Encryptor::Init(const std::string& filePath)
{
	if (StringParser::Get().getCapMap().empty() && StringParser::Get().getLowMap().empty())
		StringParser::Get().parseFile(filePath);

	EcapCode = StringParser::Get().getCapMap();
	ElowCode = StringParser::Get().getLowMap();
}

std::string Encryptor::EncryptMessage(const std::string& message) const
{
	std::string encryptResult;

	for (int i = 0; i < message.size(); i++)
	{
		char temp = message[i];
		if (EcapCode.contains(temp))
		{
			encryptResult += EcapCode.at(temp);

			// This is one way to do things is to use iterators, but i already checked if the map contains `temp` therefore,
			// no need to use find again which is in log time worst time complexity. Using the at function will not throw
			// since i am sure that the temp value exists in this if statement since it is already checked in the condition
			//std::unordered_map<char, char>::const_iterator it = capCode.find(temp);
			//encryptResult.push_back(it->second);
		}
		else if (ElowCode.contains(temp))
		{
			encryptResult += ElowCode.at(temp);
			
			// Same comment as above
			//std::unordered_map<char, char>::const_iterator it = lowCode.find(temp);
			//encryptResult.push_back(it->second);
		}
	}

	return encryptResult;
}