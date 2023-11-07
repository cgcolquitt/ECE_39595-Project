#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include <map>
#include <string>
#include "DoubleStruct.h"
#include "Map.h"


class SymbolTable : Map {
public:
    void createSymbolTable(std::string var, Double loclen);  
    void createSymbolTableSub(std::string var, Double loclen);
};


#endif /* SYMBOLTABLE_H_*/