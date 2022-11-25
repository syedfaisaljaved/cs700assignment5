/*****************************
 * @name Module Name: Morse Code Encoder/Decoder
 * @author Faisal Javed
 * @date 24th November, 2022
 * Purpose: CS-700 Assignment 5
 * Student ID: 200491169
 ****************************/

#pragma once
#include <unordered_map>
#include "Binary_Tree.h"

class MorseCode {
private:
    Binary_Tree<char>* binaryTree;
    std::unordered_map<char, std::string> morseCodeMap;
    BTNode<char>* addNodeBT(char alphabet, const std::string& codePath, unsigned int index, Binary_Tree<char>* bt);
    void decode(const std::string& morseCodeLetter, unsigned int index, Binary_Tree<char>* bt);
    void checkMessageForErrors(const std::string &message);
    void checkMorseCodeForErrors(const std::string& morseCodeMessage);
public:
    MorseCode();
    void mapMorseCode();
    void encodeMessage(std::string& message);
    void decodeMorseCode(const std::string& morseCode);
};
