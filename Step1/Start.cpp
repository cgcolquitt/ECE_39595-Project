#include <iostream>
#include <memory>
#include "Start.h"
#include "stmt.h"

Start::Start() {}

std::unique_ptr<Stmt> Start::makeStart(int x) {
    auto OP_START_PROGRAM = std::make_unique<Stmt>(x);
    return OP_START_PROGRAM;
}