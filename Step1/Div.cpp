#include <iostream>
#include <memory>
#include "Div.h"
#include "stmt.h"

Div::Div() {}

std::unique_ptr<Stmt> Div::makeDiv(int x) {
    auto OP_DIV = std::make_unique<Stmt>(x);
    return OP_DIV;
}