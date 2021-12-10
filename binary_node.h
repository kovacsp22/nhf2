//
// Created by balin on 10/25/2021.
//

#ifndef BINARY_NODE_H
#define BINARY_NODE_H


struct BinaryNode {
    BinaryNode *parent,*left,*right;
    long int value;

    BinaryNode(): parent(nullptr), left(nullptr), right(nullptr), value(0){};
    BinaryNode(long int v, BinaryNode* p): parent(p), left(nullptr), right(nullptr), value(v){};
};


#endif //BINARY_NODE_H
