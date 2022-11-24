//
// Created by Faisal Javed on 24/11/22.
//

#include "TreeNode.h"
#include <iostream>

using namespace std;

TreeNode::TreeNode() {
    this->root = new BTNode<char>('*', NULL, NULL);
}

void TreeNode::addRootNodeToTree(char alphabet, const string& codePath) {
    addNode(alphabet, codePath, 0, root);
}

BTNode<char> * TreeNode::addNode(char alphabet, const string& codePath, unsigned int index, BTNode<char>* rootNode) {
    if(rootNode == NULL){
        rootNode = new BTNode<char>(NULL);
    }

    if(codePath[index] == '.'){
        rootNode->left = addNode(alphabet, codePath, ++index, rootNode->left);
    } else if(codePath[index] == '-'){
        rootNode->right = addNode(alphabet, codePath, ++index, rootNode->right);
    } else {
        rootNode->data = alphabet;
    }

    return rootNode;
}

void TreeNode::decode(const string &morseCode, unsigned int index, BTNode<char> *rootNode) {
    string decodedMessage;

}