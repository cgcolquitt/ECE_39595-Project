#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <fstream>
#include <memory>
#include "stmt.h"

class Parser : public Stmt {
public: 
    void instructionBuffer(std::string infile);
    void symbolTable(std::string infile);
    void stringBuffer(std::string infile);
};

#endif /* PARSER_H_ */