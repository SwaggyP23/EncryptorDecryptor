#include "Decryptor.h"
#include "Encryptor.h"
#include "Log.h"

#include <iostream>

int main()
{
	reda::Log::Init(); // Initializing the loggin library.

	Encryptor::Init("res/Key.txt");
	Decryptor::Init("res/Key.txt");

	std::string Encrypted = Encryptor::Get().EncryptMessage("Hello Reda, how are you mate(?) All good and you? last day hasn't been so good for me i lost 500$");
	LOG_INFO("Encrypted message is: {0}", Encrypted);

	std::string origin = Decryptor::Get().DecryptMessage(Encrypted);
	LOG_INFO("Original message is: {0}", origin);

	std::cin.get();
}