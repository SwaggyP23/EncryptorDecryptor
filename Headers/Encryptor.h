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

	static std::unordered_map<char, std::string> EcapCode;
	static std::unordered_map<char, std::string> ElowCode;
	static std::unordered_map<char, std::string> EAscCode;
};

#endif // _ENCRYPTOR_