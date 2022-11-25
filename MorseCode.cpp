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

    /**
     * creating an object of input file stream to perform read operations.
     * takes @a StudentDataCollection.getSecondFileInputName function as a @c string argument which returns the file name.
     * */
    ifstream fileStream("Morse_Code.txt");

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!fileStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to read file.");
    }

    string line; /// creating a variable to store each line from file

    /// while loop to iterate over all the content of file
    while (getline(fileStream, line)) {
        char alphabet = line[0]; /// storing the alphabet
        string morseCode = line.substr(1, line.size()); /// storing the morse code
        morseCodeMap[alphabet] = morseCode; /// mapping alphabet and morse code
        addNodeBT(alphabet, morseCode, 0, binaryTree); /// calling func @a MorseCoe::addNodeBT to add alphabets to binary tree
    }

    fileStream.close(); /// closing the file stream
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
    /// checking if the root node is null or not
    if (rootTree->is_null()) {
        rootTree->setRoot(new BTNode<char>(' ')); /// creating a root node in the binary tree
    }

    /// traverse to left tree is '.' is encountered
    if (codePath[index] == '.') {
        auto left = rootTree->get_left_subtree(); /// storing the left subtree into a variable
        rootTree->getRoot()->left = addNodeBT(alphabet, codePath, ++index, &left); /// assigning left node of root a new subtree
    }
    /// traverse to left tree is '-' is encountered
    else if (codePath[index] == '-') {
        auto right = rootTree->get_right_subtree(); /// storing the right subtree into a variable
        rootTree->getRoot()->right = addNodeBT(alphabet, codePath, ++index, &right); /// assigning right node of root a new subtree
    }
    /// else set the data of the node
    else {
        rootTree->set_data(alphabet); /// set set the alphabet to the node data
    }

    return rootTree->getRoot(); /// return the node
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

    checkMessageForErrors(message); /// calling @a MorseCode::checkMessageForErrors to check for errors in the message
    string morseCode; /// creating a variable to store encoded morse code

    /// using a for loop to encode the message
    for (char alphabet: message) {
        /// check if the char is whitespace then add a delimiter '/' and a whitespace to it
        if (alphabet == ' ') {
            morseCode += "/ ";
            continue;
        }
        /// if the char is in uppercase convert it lowercase as all the tree contains lowercase letters
        if (isupper(alphabet)) {
            alphabet = tolower(alphabet); /// converting uppercase to lowercase
        }

        morseCode += morseCodeMap[alphabet] + ' '; /// adding the the morsecode to the string to get a full encoded message
    }

    message = morseCode; /// re-assigning message to morse code to help decode the message without returning a string
    cout << morseCode << endl; /// print the morse code after encoding the message
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
    checkMorseCodeForErrors(morseCode); /// calling func @a MorseCode::checkMorseCodeForErrors to check for errors in encoded message

    /**
     * creating an object of @c istringstream class to stream the string into different variables.
     * Takes a string as an argument.
     * */
    istringstream stringstream(morseCode);
    string morseCodeLetter; /// stores morse code of a letter
    while(stringstream >> morseCodeLetter){
        decode(morseCodeLetter, 0, binaryTree); /// calling func @a MorseCode::decode to decode the morse code
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
    char morseCodeChar = morseCodeLetter[index]; /// storing a char of the morse code

    /// check if the char matches then go to left subtree
    if(morseCodeChar == '.'){
        auto left = rootTree->get_left_subtree(); /// storing the left subtree into a variable
        decode(morseCodeLetter, ++index, &left); /// recursive calling the func to traverse the tree
    }
    /// check if the char matches then go to right subtree
    else if(morseCodeChar == '-'){
        auto right = rootTree->get_right_subtree(); /// storing the right subtree into a variable
        decode(morseCodeLetter, ++index, &right); /// recursive calling the func to traverse the tree
    }
    /// check if the char matches whitespace then print it
    else if(morseCodeChar == '/'){
        cout << " ";
    }
    /// else print the char inside the current node
    else {
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
    /// using try catch to throw and catch an exception
    try{
        /// using for loop to iterate over the message
        for(const char alphabet: message){
            /// check if char is not alpha nor whitespace then throw exception
            if(!isalpha(alphabet) && alphabet != ' '){
                throw exception(); /// throwing exception
            }
        }
    }catch(exception e){
        /// printing the exception
        cout << "Error: message should only contains alphabets and whitespaces." << endl;
        /// exiting the program
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
    /// using try catch to throw and catch an exception
    try{
        /// using for loop to iterate over the message
        for(const char morseCode: morseCodeMessage){
            /// check if char '.', '-', or '/' then continue else throw exception
            if(morseCode == '.' || morseCode == '-' || morseCode == '/' || morseCode == ' '){
                continue;
            }
            throw exception(); /// throwing exception
        }
    }catch(exception e){
        /// printing the exception
        cout << "Error: morse code is not properly encoded." << endl;
        /// exiting the program
        exit(0);
    }
}

