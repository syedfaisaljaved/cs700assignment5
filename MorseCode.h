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

/**
 * <br><br> Module Name: Morse Code Encoder/Decoder <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 24th November, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class MorseCode which contains variables, methods and constructor.
 * */
class MorseCode {
private:
    /**
     * @brief BinaryTree pointer object.
     * */
    Binary_Tree<char>* binaryTree;
    /**
     * @brief unordered map variable to contain mapped morse code and alphabet values.
     * */
    std::unordered_map<char, std::string> morseCodeMap;
    /**
     * @brief add.
     * */
    BTNode<char>* addNodeBT(char alphabet, const std::string& codePath, unsigned int index, Binary_Tree<char>* rootTree);
    /**
     * @brief Customer pointer object.
     * */
    void decode(const std::string& morseCodeLetter, unsigned int index, Binary_Tree<char>* rootTree);
    /**
     * @brief Customer pointer object.
     * */
    void checkMessageForErrors(const std::string &message);
    /**
     * @brief Customer pointer object.
     * */
    void checkMorseCodeForErrors(const std::string& morseCodeMessage);
public:
    /**
     * @brief Constructor taking no param
     * @post Post Condition - initialized binary tree.
     * @bug no known bug
     * */
    MorseCode();
    void mapMorseCode();
    void encodeMessage(std::string& message);
    void decodeMorseCode(const std::string& morseCode);
};
