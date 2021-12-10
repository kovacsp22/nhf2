//
// Created by balin on 10/25/2021.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class NoLeftChildException : public std::exception {
public:
    const char *what() const noexcept { return "Node's left child does not exists"; }
};

class NoRightChildException : public std::exception {
public:
    const char *what() const noexcept { return "Node's right child does not exists"; }
};

class NoMiddleChildException : public std::exception {
public:
    const char *what() const noexcept { return "Node's middle child does not exists"; }
};

class NoParentException : public std::exception {
public:
    const char *what() const noexcept { return "Node's parent does not exists"; }
};

class CommandNotSupportedException : public std::exception {
public:
    const char *what() const noexcept { return "Command not supported"; }
};

class ValueOutOfBoundException : public std::exception {
    const char *what() const noexcept { return "Value out of bound"; }
};

class FormatErrorException : public std::exception {
    const char *what() const noexcept { return "Format error"; }
};

class CommandFailedException : public std::exception {
    const char *what() const noexcept { return "Command failed"; }
};

#endif //TERNARY_EXCEPTIONS_H
