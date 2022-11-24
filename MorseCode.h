//
// Created by Faisal Javed on 24/11/22.
//

#pragma once
#include <unordered_map>
#include "NodeTree.h"

class MorseCode{
private:
    std::unordered_map<char, std::string> morseCodeMap;
    NodeTree* node;
    void mapMorseCode();
public:
    MorseCode();
};
