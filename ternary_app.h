#ifndef TERNARY_APP_H
#define TERNARY_APP_H

#include <string>
#include "ternary_tree.h"
#include "exceptions.h"

class TernaryApp {
protected:
    TernaryTree *tree;
    BinaryTree *treeB;
public:
    TernaryApp();
    TernaryApp(std::string command_line) noexcept(false);
    ~TernaryApp();
    void processCommandLine(std::string command_line) noexcept(false);
    std::string dumpTernaryTree();
    std::string dumpBinaryTree();
};


#endif //TERNARY_APP_H
