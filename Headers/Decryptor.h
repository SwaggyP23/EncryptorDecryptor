#pragma once

#ifndef _DECRYPTOR_
#define _DECRYPTOR

#include <string>
#include <unordered_map>

class Decryptor
{
public:

	static void Init(const std::string& filePath);

	static Decryptor& Get();

	std::string DecryptMessage(const std::string& message) const;

private:
	Decryptor();

	static std::unordered_map<char, char> DcapCode;
	static std::unordered_map<char, char> DlowCode;
};

#endif // _DECRYPTOR_

