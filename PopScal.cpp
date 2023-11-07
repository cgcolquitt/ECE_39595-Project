#include <iostream>
#include <memory>
#include "PopScal.h"
#include "stmt.h"

PopScal::PopScal() {}

std::unique_ptr<Stmt> PopScal::makePopScal(int x) {
    auto OP_POPSCAL = std::make_unique<Stmt>(x);
    return OP_POPSCAL;
}