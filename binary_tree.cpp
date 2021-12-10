//
// Created by balin on 10/25/2021.
//

#include "binary_tree.h"
#include <sstream>

/* A root alapján létrehozza a BinaryTree objektumot */
BinaryTree::BinaryTree(TernaryNode *root) {
    this->root=_knuth(root, nullptr);
}

BinaryTree::~BinaryTree() {
    _destroy(root);
}

/* Kinyomtatja a bináris fa tartalmát */
std::ostream &operator<<(std::ostream &os, const BinaryTree &bt) {
    os<<bt.dumpTree();
    return os;
}

/*
 * A metódus dumpolja a tárolt hármas fát a feladatkiírásban leírtak szerint
 */
std::string BinaryTree::dumpTree() const {
    std::stringstream o;
    _preorder(root,o);
    return o.str();
}

BinaryNode* BinaryTree::_knuth(TernaryNode *n, BinaryNode *p){
    if(n==nullptr) return nullptr;

    auto *newN = new BinaryNode(n->value, p);
    if(n->parent!=nullptr) {
        if (n->parent->middle==n) newN->right=_knuth(n->parent->right, newN);
        else if (n->parent->left==n) newN->right=_knuth(n->parent->middle, newN);
    }
    if(n->left) newN->left=_knuth(n->left, newN);
    else if(n->middle) newN->left=_knuth(n->middle, newN);
    else if(n->right) newN->left=_knuth(n->right, newN);

    return newN;
}

void BinaryTree::_destroy(BinaryNode *n){
    if(n!=nullptr){
        _destroy(n->left);
        _destroy(n->right);
        delete n;
    }
}

BinaryNode* BinaryTree::_copyOf(BinaryNode* n, BinaryNode* p){
    if(n==nullptr) return nullptr;
    auto* x=new BinaryNode(n->value, p);
    x->left= _copyOf(n->left, x);
    x->right= _copyOf(n->right, x);
    return x;
}

std::ostream& BinaryTree::_preorder(BinaryNode* i, std::ostream& o) const{
    if (i == nullptr) o<<"(-";
    else {
        o<<"("<<i->value;
        if(i->left||i->right){
            _preorder(i->left, o);
            _preorder(i->right, o);
        }
    }
    o<<")";
    return o;
}
