#include <iostream>
#include <memory>
#include "PushI.h"
#include "stmt.h"

PushI::PushI() {}

std::unique_ptr<Stmt> PushI::makePushI(int x) {
    auto OP_PUSHI = std::make_unique<Stmt>(x);
    return OP_PUSHI;
}