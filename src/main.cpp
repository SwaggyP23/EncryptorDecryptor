#include "Decryptor.h"
#include "Encryptor.h"

#include <iostream>

int foo(void) {
	int joe = 1234, fred;
	__asm {
		mov eax, joe;
		add eax, 2;
		mov fred, eax;
	};
	return fred;
}

int main()
{
	std::cout << "Foo output: " << foo() << std::endl;
	Encryptor::Init("res/Key.txt");
	Decryptor::Init("res/Key.txt");

	std::string message;
	std::cout << "Enter your message: ";
	getline(std::cin, message);

	std::string Encrypted = Encryptor::Get().EncryptMessage(message);
	std::cout << "Encrypted message is: " << Encrypted << std::endl;

	char i;
	std::cout << "Do u want to decrypt it? [Y/n] ";
	std::cin >> i;
	if (i == 'Y') {
		std::string origin = Decryptor::Get().DecryptMessage(Encrypted);
		std::cout << "Original message is: " << origin << std::endl;
	}

	std::cin.get();
}