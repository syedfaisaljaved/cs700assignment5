//
// Created by Faisal Javed on 24/11/22.
//

#pragma once

#include "Binary_Tree.h"

class NodeTree: public Binary_Tree<char>{
private:
public:
    NodeTree();
    void addNoteToTree();
    void decodeMorseCode();
};
