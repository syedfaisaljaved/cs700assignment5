//
// Created by Faisal Javed on 24/11/22.
//

#pragma once
#include "TreeNode.h"
#include "Binary_Tree.h"

class MorseCode{
private:
    TreeNode* treeNode;
    void mapMorseCode();

public:
    MorseCode();
    void encodeMessage(const std::string& message);
    void decodeMorseCode(const std::string& morseCode);
};
