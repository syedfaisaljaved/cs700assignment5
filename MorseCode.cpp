/*****************************
 * @name Module Name: Morse Code Encoder/Decoder
 * @author Faisal Javed
 * @date 24th November, 2022
 * Purpose: CS-700 Assignment 5
 * Student ID: 200491169
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams.
#include <fstream> /// library that implements high-level input/output operations on file based streams.

/**
 * @file MorseCode.h
 * @brief user-defined header file MorseCode.h to propagate declarations to code file. <br >
 * */
#include "MorseCode.h"
/**
 * @file Binary_Tree.h
 * @brief user-defined header file Binary_Tree.h to propagate declarations to code file. <br >
 * */
#include "Binary_Tree.h"

/**
 * 'namespace' is used to organise the names of program entities.
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std.
 * */
using namespace std;

MorseCode::MorseCode() {
    binaryTree = new Binary_Tree<char>(); /// object @a MorseCode::binaryTree is initialized in the constructor.
}

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
void MorseCode::mapMorseCode() {
    ifstream fileStream("Morse_Code.txt");

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!fileStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to read file.");
    }

    string line;

    while (getline(fileStream, line)) {
        char alphabet = line[0];
        string morseCode = line.substr(1, line.size());
        morseCodeMap[alphabet] = morseCode;
        addNodeBT(alphabet, morseCode, 0, binaryTree);
    }

    fileStream.close();
}

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
BTNode<char> *MorseCode::addNodeBT(char alphabet, const string &codePath, unsigned int index, Binary_Tree<char>* rootTree) {
    if (rootTree->is_null()) {
        rootTree->setRoot(new BTNode<char>(' '));
    }

    if (codePath[index] == '.') {
        auto left = rootTree->get_left_subtree();
        rootTree->getRoot()->left = addNodeBT(alphabet, codePath, ++index, &left);
    } else if (codePath[index] == '-') {
        auto right = rootTree->get_right_subtree();
        rootTree->getRoot()->right = addNodeBT(alphabet, codePath, ++index, &right);
    } else {
        rootTree->set_data(alphabet);
    }

    return rootTree->getRoot();
}

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
void MorseCode::encodeMessage(string &message) {
    checkMessageForErrors(message);
    string morseCode;
    for (char alphabet: message) {
        if (alphabet == ' ') {
            morseCode += "/ ";
            continue;
        }

        if (isupper(alphabet)) {
            alphabet = tolower(alphabet);
        }

        morseCode += morseCodeMap[alphabet] + ' ';
    }

    message = morseCode;
    cout << morseCode << endl;
}

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
void MorseCode::decodeMorseCode(const std::string &morseCode) {
    checkMorseCodeForErrors(morseCode);
    istringstream stringstream(morseCode);
    string morseCodeLetter;
    while(stringstream >> morseCodeLetter){
        decode(morseCodeLetter, 0, binaryTree);
    }
}

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
void MorseCode::decode(const string &morseCodeLetter, unsigned int index, Binary_Tree<char> *rootTree) {
    char morseCodeChar = morseCodeLetter[index];

    if(morseCodeChar == '.'){
        auto left = rootTree->get_left_subtree();
        decode(morseCodeLetter, ++index, &left);
    } else if(morseCodeChar == '-'){
        auto right = rootTree->get_right_subtree();
        decode(morseCodeLetter, ++index, &right);
    } else if(morseCodeChar == '/'){
        cout << " ";
    } else {
        cout << rootTree->get_data();
    }
}

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
void MorseCode::checkMessageForErrors(const string &message) {
    try{
        for(const char alphabet: message){
            if(!isalpha(alphabet) && alphabet != ' '){
                throw exception();
            }
        }
    }catch(exception e){
        cout << "Error: message should only contains alphabets and whitespaces." << endl;
        exit(0);
    }
}

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
void MorseCode::checkMorseCodeForErrors(const std::string& morseCodeMessage) {
    try{
        for(const char morseCode: morseCodeMessage){
            if(morseCode == '.' || morseCode == '-' || morseCode == '/'){
                continue;
            }

            throw exception();
        }
    }catch(exception e){
        cout << "Error: morse code is not properly encoded." << endl;
        exit(0);
    }
}

