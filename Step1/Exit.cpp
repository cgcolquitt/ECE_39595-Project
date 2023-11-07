#include <iostream>
#include <memory>
#include "Exit.h"
#include "stmt.h"

Exit::Exit() {}

std::unique_ptr<Stmt> Exit::makeExit(int x) {
    auto OP_EXIT_PROGRAM = std::make_unique<Stmt>(x);
    return OP_EXIT_PROGRAM;
}