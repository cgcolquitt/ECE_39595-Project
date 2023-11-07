#include <iostream>
#include <memory>
#include "Return.h"
#include "stmt.h"

Return::Return() {}

std::unique_ptr<Stmt> Return::makeReturn(int x) {
    auto OP_RETURN = std::make_unique<Stmt>(x);
    return OP_RETURN;
}