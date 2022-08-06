#include "Decryptor.h"
#include "Parsers/StringParser.h"

std::unordered_map<char, std::string> Decryptor::DcapCode;
std::unordered_map<char, std::string> Decryptor::DlowCode;
std::unordered_map<char, std::string> Decryptor::DAscCode;

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
	if (   StringParser::Get().getCapMap().empty() 
		&& StringParser::Get().getLowMap().empty()
		&& StringParser::Get().getAscMap().empty()
		)
			StringParser::Get().parseFile(filePath);

	DcapCode = StringParser::Get().getCapMap();
	DlowCode = StringParser::Get().getLowMap();
	DAscCode = StringParser::Get().getAscMap();
}

std::string Decryptor::DecryptMessage(const std::string& message) const
{
	std::string DecryptedResult;
	
	for (unsigned int i = 0; i < message.size(); i += 2)
	{
		std::string temp(&message[i], &message[i] + 2);
		for (auto&[key, code] : DcapCode)
		{
			if (code == temp) {
				DecryptedResult += key;
				break;
			}
		}

		for (auto&[key, code] : DlowCode)
		{
			if (code == temp) {
				DecryptedResult += key;
				break;
			}
		}

		for (auto&[key, code] : DAscCode)
		{
			if (code == temp) {
				DecryptedResult += key;
				break;
			}
		}
	}

	return DecryptedResult;
}