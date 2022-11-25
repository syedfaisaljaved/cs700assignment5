/*****************************
 * @name Module Name: Morse Code Encoder/Decoder
 * @author Faisal Javed
 * @date 24th November, 2022
 * Purpose: CS-700 Assignment 5
 * Student ID: 200491169
 ****************************/

/**
  * Code placed here is included only once per translation unit.<br>
  * '#pragma once' is non-standard preprocessor directive intended for implementing compiler-specific preprocessor instructions.<br>
  * It's purpose is to replace the include guards that you use in header files to avoid multiple inclusion.<br>
  * */
#pragma once
#include <unordered_map> /// library that contains unordered map <br>
/**
 * @file Binary_Tree.h
 * @brief user-defined header file Binary_Tree.h to propagate declarations to code file. <br >
 * */
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
     * Module Name: Morse Code Encoder/Decoder <br>
     * Author: Faisal Javed <br>
     * Date of Creation: 24th November, 2022 <br>
     * Purpose: the function sets the data of the node in the binary tree after traversing to the right position using morse code <br>
     *          @param [in] alphabet
     *          @param [in] codePath
     *          @param [in] index
     *          @param [in] rootTree
     *          @return [out] BTNode<char>
     *          @pre Pre Condition - a char containing alphabet, a string containing morse code, an index and a binary tree is passed
     *          @post Post Condition - binary tree is filled with values.
     *          @bug No known bugs
     * */
    BTNode<char>* addNodeBT(char alphabet, const std::string& codePath, unsigned int index, Binary_Tree<char>* rootTree);
    /**
     * Module Name: Morse Code Encoder/Decoder <br>
      * Author: Faisal Javed <br>
      * Date of Creation: 24th November, 2022 <br>
      * Purpose: the function decodes the morse code into a message by traversing through the tree <br>
      *          @param [in] morseCodeLetter
      *          @param [in] index
      *          @param [in] rootTree
      *          @return [out] void
      *          @pre Pre Condition - a string morsecode, an index, and a binary tree is passed
      *          @post Post Condition - morse code is decoded
      *          @bug No known bugs
      * */
    void decode(const std::string& morseCodeLetter, unsigned int index, Binary_Tree<char>* rootTree);
    /**
     * Module Name: Morse Code Encoder/Decoder <br>
     * Author: Faisal Javed <br>
     * Date of Creation: 24th November, 2022 <br>
     * Purpose: the function checks for the errors in the message to be encoded <br>
     *          @param [in] message
     *          @return [out] void
     *          @pre Pre Condition - a string message is passed
     *          @post Post Condition - throws exception is the message contains chars which are not alpha or whitespace
     *          @bug No known bugs
     * */
    void checkMessageForErrors(const std::string &message);
    /**
     * Module Name: Morse Code Encoder/Decoder <br>
     * Author: Faisal Javed <br>
     * Date of Creation: 24th November, 2022 <br>
     * Purpose: the function checks for the errors in the morse code to be decoded <br>
     *          @param [in] message
     *          @return [out] void
     *          @pre Pre Condition - a string morsecodeMessage is passed
     *          @post Post Condition - throws exception is the morse code contains chars apart from '.' , '_' and '/'
     *          @bug No known bugs
     * */
    void checkMorseCodeForErrors(const std::string& morseCodeMessage);
public:
    /**
     * @brief Constructor taking no param
     * @post Post Condition - initialized binary tree.
     * @bug no known bug
     * */
    MorseCode();
    /**
     * Module Name: Morse Code Encoder/Decoder <br>
     * Author: Faisal Javed <br>
     * Date of Creation: 24th November, 2022 <br>
     * Purpose: the function read a file then maps the alphabet to its morse code and stores all the alphabet in the binary tree <br>
     *          @param [in] void
     *          @return [out] void
     *          @post Post Condition - binary tree is filled with values.
     *          @bug No known bugs
     * */
    void mapMorseCode();
    /**
     * Module Name: Morse Code Encoder/Decoder <br>
     * Author: Faisal Javed <br>
     * Date of Creation: 24th November, 2022 <br>
     * Purpose: the function encodes the message into morse code <br>
     *          @param [in] message
     *          @return [out] void
     *          @pre Pre Condition - a string message is passed
     *          @post Post Condition - message is encoded
     *          @bug No known bugs
     * */
    void encodeMessage(std::string& message);
    /**
     * Module Name: Morse Code Encoder/Decoder <br>
     * Author: Faisal Javed <br>
     * Date of Creation: 24th November, 2022 <br>
     * Purpose: the function decodes the morsecode into message <br>
     *          @param [in] morseCode
     *          @return [out] void
     *          @pre Pre Condition - a string morsecode is passed
     *          @post Post Condition - morsecode is decoded
     *          @bug No known bugs
     * */
    void decodeMorseCode(const std::string& morseCode);
};
