#include <iostream>
#include <memory>
#include "Dup.h"
#include "stmt.h"

Dup::Dup() {}

std::unique_ptr<Stmt> Dup::makeDup(int x) {
    auto OP_DUP = std::make_unique<Stmt>(x);
    return OP_DUP;
}