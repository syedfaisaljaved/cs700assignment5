#include <iostream>
#include "MorseCode.h"

using namespace std;

int main() {
    MorseCode morseCode;
    cout << morseCode.encodeMessage("Hello");
    return 0;
}
