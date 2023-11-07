#include <iostream>
#include <memory>
#include "Negate.h"
#include "stmt.h"

Negate::Negate() {}

std::unique_ptr<Stmt> Negate::makeNegate(int x) {
    auto OP_NEGATE = std::make_unique<Stmt>(x);
    return OP_NEGATE;
}