//
// Created by gabriel on 21/03/18.
//

#include <utility>
#include <vector>
#include "Node.h"

Node::Node(Node* leftChild, Node* rightChild) :
        parent(nullptr),
        leftChild(leftChild),
        rightChild(rightChild),
        character(0){}

Node::Node(Node* parent, unsigned char character) :
        parent(parent),
        leftChild(nullptr),
        rightChild(nullptr),
        character(character) {}

Node::~Node() {
    destroy(this);
}

bool Node::isLeaf() {
    return leftChild == nullptr;
}

bool Node::isRoot() {
    return parent == nullptr;
}

string Node::getCode() {
    if(this->isRoot()) return "";
    string thisCode(1, this->character);
    return thisCode + parent->getCode();
}

void Node::destroy(Node *node) {
    if(!node->isLeaf()) {
        destroy(node->leftChild);
        destroy(node->rightChild);
    }
    delete node;
}
