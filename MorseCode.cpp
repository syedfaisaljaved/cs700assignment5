//
// Created by Faisal Javed on 24/11/22.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "MorseCode.h"
#include "Binary_Tree.h"

using namespace std;

MorseCode::MorseCode() {
    root = new BTNode<char>('*');
    mapMorseCode();
}

void MorseCode::mapMorseCode() {
    ifstream fileStream("/Users/faisal/CLionProjects/cs700assignment5/Morse_Code.txt");

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
        addNode(alphabet, morseCode, 0, root);
    }

    fileStream.close();
}

BTNode<char> *MorseCode::addNode(char alphabet, const string &codePath, unsigned int index, BTNode<char>* binaryNode) {
    if (binaryNode == NULL) {
        binaryNode = new BTNode<char>(' ');
    }

    if (codePath[index] == '.') {
        binaryNode->left = addNode(alphabet, codePath, ++index, binaryNode->left);
    } else if (codePath[index] == '-') {
        binaryNode->right = addNode(alphabet, codePath, ++index, binaryNode->right);
    } else {
        binaryNode->data = alphabet;
    }

    return binaryNode;
}

void MorseCode::encodeMessage(string &message) {
    string morseCode;
    for (char alphabet: message) {
        if (alphabet == ' ') {
            morseCode += '/';
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

void MorseCode::decodeMorseCode(const std::string &morseCode) {
    istringstream stringstream(morseCode);
    string morseCodeLetter;
    while(stringstream >> morseCodeLetter){
        decode(morseCodeLetter, 0, root);
    }
}

void MorseCode::decode(const string &morseCodeLetter, unsigned int index, BTNode<char> *binaryNode) {
    char morseCodeChar = morseCodeLetter[index];

    if(morseCodeChar == '.'){
        decode(morseCodeLetter, ++index, binaryNode->left);
    } else if(morseCodeChar == '-'){
        decode(morseCodeLetter, ++index, binaryNode->right);
    } else if(morseCodeChar == '/'){
        cout << " ";
    } else {
        char result = binaryNode->data;
        cout << result;
    }
}

void MorseCode::checkMessageForErrors(const string &message) {
    try{
        for(const char alphabet: message){
            if(!isalpha(alphabet)){
                throw exception();
            }
        }
    }catch(exception e){
        cout << "Error: message should only contains alphabets." << endl;
    }
}

void MorseCode::checkMorseCodeForErrors(const std::string morseCodeMessage) {
    try{
        for(const char morseCode: morseCodeMessage){
            if(morseCode != '.' && morseCode != '-'){
                throw exception();
            }
        }
    }catch(exception e){
        cout << "Error: morse code is not properly encoded." << endl;
    }
}

