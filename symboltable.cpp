#include <iostream>
#include <map>
#include <string>
#include <memory>
#include "symboltable.h"
#include "Map.h"

void SymbolTable::createSymbolTable(std::string var, Double loclen) {
    insert(var, loclen);
}

void SymbolTable::createSymbolTableSub(std::string var, Double loclen) {
    insertSub(var, loclen);
}

