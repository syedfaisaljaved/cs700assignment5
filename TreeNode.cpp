//
// Created by Faisal Javed on 24/11/22.
//

#include "TreeNode.h"

TreeNode::TreeNode() {
    this->root = new BTNode<char>('*', NULL, NULL);
}

void TreeNode::addRootNodeToTree(char alphabet, const std::string& codePath) {
    addNode(alphabet, codePath, 0, this->root);
}

void TreeNode::decodeMorseCode() {

}

BTNode<char> * TreeNode::addNode(char alphabet, const std::string& codePath, unsigned int index, BTNode<char>* rootNode) {
    if(rootNode == NULL){
        this->root = new BTNode<char>('*', NULL, NULL);
    }

    if(codePath[index] == '.'){
        rootNode->left = addNode(alphabet, codePath, ++index, rootNode->left);
    } else if(codePath[index] == '_'){
        rootNode->right = addNode(alphabet, codePath, ++index, rootNode->right);
    } else {
        rootNode->data = alphabet;
    }

    return rootNode;
}
