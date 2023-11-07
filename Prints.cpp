#include <iostream>
#include <memory>
#include "Prints.h"
#include "stmt.h"

Prints::Prints() {}

std::unique_ptr<Stmt> Prints::makePrints(int x) {
    auto OP_PRINTS = std::make_unique<Stmt>(x);
    return OP_PRINTS;
}