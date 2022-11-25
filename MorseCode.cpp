
#include <iostream>
#include <fstream>
#include "MorseCode.h"
#include "Binary_Tree.h"

using namespace std;

MorseCode::MorseCode() {
    binaryTree = new Binary_Tree<char>();
}

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

BTNode<char> *MorseCode::addNodeBT(char alphabet, const string &codePath, unsigned int index, Binary_Tree<char>* bt) {
    if (bt->is_null()) {
        bt->setRoot(new BTNode<char>(' '));
    }

    if (codePath[index] == '.') {
        auto left = bt->get_left_subtree();
        bt->getRoot()->left = addNodeBT(alphabet, codePath, ++index, &left);
    } else if (codePath[index] == '-') {
        auto right = bt->get_right_subtree();
        bt->getRoot()->right = addNodeBT(alphabet, codePath, ++index, &right);
    } else {
        bt->set_data(alphabet);
    }

    return bt->getRoot();
}

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

void MorseCode::decodeMorseCode(const std::string &morseCode) {
    checkMorseCodeForErrors(morseCode);
    istringstream stringstream(morseCode);
    string morseCodeLetter;
    while(stringstream >> morseCodeLetter){
        decode(morseCodeLetter, 0, binaryTree);
    }
}

void MorseCode::decode(const string &morseCodeLetter, unsigned int index, Binary_Tree<char> *bt) {
    char morseCodeChar = morseCodeLetter[index];

    if(morseCodeChar == '.'){
        auto left = bt->get_left_subtree();
        decode(morseCodeLetter, ++index, &left);
    } else if(morseCodeChar == '-'){
        auto right = bt->get_right_subtree();
        decode(morseCodeLetter, ++index, &right);
    } else if(morseCodeChar == '/'){
        cout << " ";
    } else {
        cout << bt->get_data();
    }
}

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

void MorseCode::checkMorseCodeForErrors(const std::string& morseCodeMessage) {
    try{
        for(const char morseCode: morseCodeMessage){
            if(morseCode == '.' || morseCode == '-' || morseCode == '/' || morseCode == ' '){
                continue;
            }

            throw exception();
        }
    }catch(exception e){
        cout << "Error: morse code is not properly encoded." << endl;
        exit(0);
    }
}

