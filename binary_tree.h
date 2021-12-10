//
// Created by balin on 10/25/2021.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <ostream>
#include <string>
#include "binary_node.h"
#include "ternary_node.h"

class BinaryTree {
    BinaryNode* _knuth(TernaryNode *n, BinaryNode *p);
    void _destroy(BinaryNode* n);
    BinaryNode* _copyOf(BinaryNode *n, BinaryNode *p);
    std::ostream& _preorder(BinaryNode* i, std::ostream& o) const;
protected:
    BinaryNode *root;
public:
    BinaryTree() = delete;
    BinaryTree(TernaryNode *root);
    ~BinaryTree();
    std::string dumpTree() const;
    friend std::ostream& operator<<(std::ostream& os, const BinaryTree& bt);

};


#endif //BINARY_TREE_H
