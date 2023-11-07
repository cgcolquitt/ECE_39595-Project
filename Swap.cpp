#include <iostream>
#include <memory>
#include "Swap.h"
#include "stmt.h"

Swap::Swap() {}

std::unique_ptr<Stmt> Swap::makeSwap(int x) {
    auto OP_SWAP = std::make_unique<Stmt>(x);
    return OP_SWAP;
}