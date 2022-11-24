//
// Created by Faisal Javed on 24/11/22.
//
#include <iostream>
#include <fstream>
#include "MorseCode.h"

using namespace std;

MorseCode::MorseCode() {
    mapMorseCode();
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
    treeNode = new TreeNode();

    while (getline(fileStream, line)) {
        char alphabet = line[0];
        string morseCode = line.substr(1, line.size());
        morseCodeMap[alphabet] = morseCode;
        treeNode->addRootNodeToTree(alphabet, morseCode);
    }

    fileStream.close();
}

string MorseCode::encodeMessage(const string& message) {
    string morseCode;
    for (char alphabet : message) {
        if (alphabet == ' ') {
            morseCode += ' ';
            continue;
        }

        morseCode += this->morseCodeMap[index];
    }

    return morseCode;
}

