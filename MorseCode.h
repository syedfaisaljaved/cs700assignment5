//
// Created by Faisal Javed on 24/11/22.
//

#pragma once
#include <unordered_map>
#include "Binary_Tree.h"

class MorseCode : public Binary_Tree<char>{
private:
    std::unordered_map<char, std::string> morseCodeMap;
    void mapMorseCode();
    BTNode<char>* addNode(char alphabet, const std::string& codePath, unsigned int index, BTNode<char>* binaryNode);
    void decode(const std::string& morseCodeLetter, unsigned int index, BTNode<char>* binaryNode);
    void checkMessageForErrors(const std::string &message);
    void checkMorseCodeForErrors(const std::string morseCode);
public:
    MorseCode();
    void encodeMessage(std::string& message);
    void decodeMorseCode(const std::string& morseCode);
};
