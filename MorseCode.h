//
// Created by Faisal Javed on 24/11/22.
//

#pragma once
#include <unordered_map>
#include "TreeNode.h"

class MorseCode{
private:
    std::unordered_map<char, std::string> morseCodeMap;
    TreeNode* treeNode;
    void mapMorseCode();
public:
    MorseCode();
    std::string encodeMessage(const std::string& message);
    std::string decodeMorseCode(std::string morseCode);
};
