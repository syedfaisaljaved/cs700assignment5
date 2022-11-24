//
// Created by Faisal Javed on 24/11/22.
//

#pragma once

#include "Binary_Tree.h"

class TreeNode: public Binary_Tree<char>{
private:
    BTNode<char> * addNode(char alphabet, const std::string& codePath, unsigned int index, BTNode<char>* rootNode);
public:
    TreeNode();
    void addRootNodeToTree(char alphabet, const std::string& codePath);
    void decode(const std::string& morseCode, unsigned int index, BTNode<char>* rootNode);
    void encode(const std::string& morseCode, unsigned int index, BTNode<char>* rootNode);
};
