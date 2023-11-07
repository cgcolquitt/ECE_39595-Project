#include <iostream>
#include <memory>
#include "Jump.h"
#include "stmt.h"

Jump::Jump() {}

std::unique_ptr<Stmt> Jump::makeJump(int x) {
    auto OP_JUMP = std::make_unique<Stmt>(x);
    return OP_JUMP;
}