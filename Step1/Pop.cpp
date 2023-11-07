#include <iostream>
#include <memory>
#include "Pop.h"
#include "stmt.h"

Pop::Pop() {}

std::unique_ptr<Stmt> Pop::makePop(int x) {
    auto OP_POP = std::make_unique<Stmt>(x);
    return OP_POP;
}