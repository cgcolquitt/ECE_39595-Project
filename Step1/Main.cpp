#include <iostream>
#include <iterator>
#include <fstream>
#include <memory>
#include "Map.h"
#include "symboltable.h"
#include "stmt.h"
#include "Start.h"
#include "Parser.h"
#include "SubroutineG.h"
#include "scanner.h"


int main(int argc, char ** argv) {
    Parser obj;
    Scanner obj1;
    std::string infile = argv[1];
    infile = infile + ".txt";

    if(obj1.scanfile(infile) != 1) {
        exit(0);
    }
    else {
        obj.stringBuffer(infile);
        obj.symbolTable(infile);
        obj.instructionBuffer(infile);
    }

    return EXIT_SUCCESS;
}

