#include <iostream>
#include <memory>
#include "PushScal.h"
#include "stmt.h"

PushScal::PushScal() {}

std::unique_ptr<Stmt> PushScal::makePushScal(int x) {
    auto OP_PUSHSCALAR = std::make_unique<Stmt>(x);
    return OP_PUSHSCALAR;
}