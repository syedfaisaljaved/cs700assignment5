/*****************************
 * @name Module Name: Morse Code Encoder/Decoder
 * @author Faisal Javed
 * @date 24th November, 2022
 * Purpose: CS-700 Assignment 5
 * Student ID: 200491169
 ****************************/


#include <iostream> /// library that controls reading from and writing to the standard streams.<br>

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

/**
 * Module Name: Morse Code Encoder/Decoder <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 24th November, 2022 <br>
 * Purpose: main() Function serves as the starting point for program execution.
 *          It has no arguments and returns 0 if the program is executed successfully. <br>
 *          @param [in] void
 *          @return [out] int
 *          @post Post Condition - int is returned.
 *          @bug No known bugs
 * */
int main() {

    /// program execution starts here.

    cout << "Enter a message" << endl; /// print to console
    string message; /// creating a variable to store user input
    getline(cin, message); /// taking user input
    MorseCode morseCode; /// creating object of class @a MorseCode
    morseCode.mapMorseCode(); /// calling function @a MorseCode.mapMorseCode
    morseCode.encodeMessage(message); /// calling function @a MorseCode::encodeMessage
    morseCode.decodeMorseCode(message); /// calling function @a MorseCode::decodeMorseCode
    return 0; /// returns 0 if the program is executed successfully because main() has a return type of integer.

    /// program terminates here.
}
