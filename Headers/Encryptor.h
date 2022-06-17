#pragma once

#ifndef _ENCRYPTOR_
#define _ENCRYPTOR_

#include <string>
#include <unordered_map>

class Encryptor
{
public:

	static void Init(const std::string& filePath);

	static Encryptor& Get();

	std::string EncryptMessage(const std::string& message) const;

private:
	Encryptor();

	static std::unordered_map<char, char> EcapCode;
	static std::unordered_map<char, char> ElowCode;
};

#endif // _ENCRYPTOR_