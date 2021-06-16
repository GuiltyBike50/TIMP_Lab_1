#pragma once
#include <vector>
#include <string>
#include <map>
class modMarshCipher
{
    int key1;
public:
    modMarshCipher()=delete;
    modMarshCipher(const int& key) :key1(key) {};
    std::string encrypt(const std::string& open_text);
    std::string decrypt(const std::string& cipher_text);
};
