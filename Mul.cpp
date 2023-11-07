#include <iostream>
#include <memory>
#include "Mul.h"
#include "stmt.h"

Mul::Mul() {}

std::unique_ptr<Stmt> Mul::makeMul(int x) {
    auto OP_MUL = std::make_unique<Stmt>(x);
    return OP_MUL;
}