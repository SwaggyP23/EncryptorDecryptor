#include "Decryptor.h"
#include "Encryptor.h"
#include "Log.h"
#include "testing/TestingStringParser.h"

#include <iostream>

int main()
{
	reda::Log::Init(); // Initializing the loggin library.

	//Encryptor::Init("res/Key.txt");
	//Decryptor::Init("res/Key.txt");

	TestingStringParser::Get().parseFile("res/Key.txt");
	CharMap CM = TestingStringParser::Get().getCharMap();
	std::unordered_map<char, std::string> resC(CM.capitalMap);
	std::unordered_map<char, std::string> resL(CM.lowerMap);

	for (auto it = resC.cbegin(); it != resC.cend(); ++it) {
		std::string temp = it->second;
		std::cout << temp << std::endl;
	}

	std::string Encrypted = Encryptor::Get().EncryptMessage("Hello Reda");
	LOG_INFO("Encrypted message is: {0}", Encrypted);

	std::string origin = Decryptor::Get().DecryptMessage(Encrypted);
	LOG_INFO("Original message is: {0}", origin);

	std::cin.get();
}