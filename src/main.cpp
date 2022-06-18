#include "Decryptor.h"
#include "Encryptor.h"
#include "Log.h"

#include <iostream>

int main()
{
	reda::Log::Init(); // Initializing the loggin library.

	Encryptor::Init("res/Key.txt");
	Decryptor::Init("res/Key.txt");

	std::string message;
	std::cout << "Enter your message: ";
	getline(std::cin, message);

	std::string Encrypted = Encryptor::Get().EncryptMessage(message);
	LOG_INFO("Encrypted message is: {0}", Encrypted);

	char i;
	std::cout << "Do u want to decrypt it? [Y/n]";
	std::cin >> i;
	if (i == 'Y') {
		std::string origin = Decryptor::Get().DecryptMessage(Encrypted);
		LOG_INFO("Original message is: {0}", origin);
	}

	std::cin.get();
}