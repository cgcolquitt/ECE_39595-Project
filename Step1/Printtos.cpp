#include <iostream>
#include <memory>
#include "Printtos.h"
#include "stmt.h"

PrintTos::PrintTos() {}

std::unique_ptr<Stmt> PrintTos::makePrintTos(int x) {
    auto OP_PRINTTOS = std::make_unique<Stmt>(x);
    return OP_PRINTTOS;
}