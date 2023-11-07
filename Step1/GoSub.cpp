#include <iostream>
#include <memory>
#include "GoSub.h"
#include "stmt.h"

GoSub::GoSub() {}

std::unique_ptr<Stmt> GoSub::makeGoSub(int x) {
    auto OP_GOSUB = std::make_unique<Stmt>(x);
    return OP_GOSUB;
}