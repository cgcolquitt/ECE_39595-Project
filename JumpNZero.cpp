#include <iostream>
#include <memory>
#include "JumpNZero.h"
#include "stmt.h"

JumpNZero::JumpNZero() {}

std::unique_ptr<Stmt> JumpNZero::makeJumpNZero(int x) {
    auto OP_JUMPNZERO = std::make_unique<Stmt>(x);
    return OP_JUMPNZERO;
}