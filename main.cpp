#include <iostream>
#include "MorseCode.h"

using namespace std;

int main() {

    cout << "Enter a message" << endl;
    string message;
    getline(cin, message);
    MorseCode morseCode;
    morseCode.encodeMessage(message);
    morseCode.decodeMorseCode(message);
    return 0;
}
