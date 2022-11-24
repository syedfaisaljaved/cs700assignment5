//
// Created by Faisal Javed on 24/11/22.
//

#pragma once

#include "Binary_Tree.h"

class TreeNode: public Binary_Tree<char>{
private:
public:
    TreeNode();
    void addNoteToTree();
    void decodeMorseCode();
};
