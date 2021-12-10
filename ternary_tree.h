//
// Created by balin on 10/25/2021.
//

#ifndef TERNARY_TREE_H
#define TERNARY_TREE_H

#include <ostream>
#include <string>
#include "ternary_node.h"
#include "binary_tree.h"
#include "exceptions.h"

enum CursorDirection {top, up, left, middle, right};

class TernaryTree {
    void _destroy(TernaryNode* n);
    TernaryNode* _copyOf(TernaryNode *n, TernaryNode *p);
    std::ostream& _preorder(TernaryNode* i, std::ostream& o) const;
protected:
    TernaryNode *root, *cursor;
public:
    TernaryTree();
    TernaryTree (const TernaryTree& _other);
    TernaryTree& operator= (const TernaryTree& _other);
    ~TernaryTree();
    void addValue(long int val);
    void rotateClockwise() noexcept(false);
    void rotateAnticlockwise() noexcept(false);
    void moveCursor(CursorDirection dir) noexcept(false);
    BinaryTree* generateBinaryTree() const;
    std::string dumpTree() const;
    friend std::ostream& operator<<(std::ostream& os, const TernaryTree& tt);
};


#endif //TERNARY_TREE_H
