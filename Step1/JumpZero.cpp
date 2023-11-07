#include <iostream>
#include <memory>
#include "JumpZero.h"
#include "stmt.h"

JumpZero::JumpZero() {}

std::unique_ptr<Stmt> JumpZero::makeJumpZero(int x) {
    auto OP_JUMPZERO = std::make_unique<Stmt>(x);
    return OP_JUMPZERO;
}