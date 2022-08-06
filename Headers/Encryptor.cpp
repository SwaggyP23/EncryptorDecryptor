#include "Encryptor.h"
#include "Parsers/StringParser.h"

std::unordered_map<char, std::string> Encryptor::EcapCode;
std::unordered_map<char, std::string> Encryptor::ElowCode;
std::unordered_map<char, std::string> Encryptor::EAscCode;

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
	if (   StringParser::Get().getCapMap().empty()
		&& StringParser::Get().getLowMap().empty()
		&& StringParser::Get().getAscMap().empty()
		)
		StringParser::Get().parseFile(filePath);

	EcapCode = StringParser::Get().getCapMap();
	ElowCode = StringParser::Get().getLowMap();
	EAscCode = StringParser::Get().getAscMap();
}

std::string Encryptor::EncryptMessage(const std::string& message) const
{
	std::string encryptResult;

	for (unsigned int i = 0; i < message.size(); i++)
	{
		char temp = message[i];
		if (EcapCode.contains(temp))
			encryptResult += EcapCode.at(temp);
		else if (ElowCode.contains(temp))
			encryptResult += ElowCode.at(temp);			
		else if (EAscCode.contains(temp))
			encryptResult += EAscCode.at(temp);
	}

	return encryptResult;
}