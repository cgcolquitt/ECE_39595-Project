#include <iostream>
#include <memory>
#include "PushArr.h"
#include "stmt.h"

PushArr::PushArr() {}

std::unique_ptr<Stmt> PushArr::makePushArray(int x) {
    auto OP_PUSHARRAY = std::make_unique<Stmt>(x);
    return OP_PUSHARRAY;
}