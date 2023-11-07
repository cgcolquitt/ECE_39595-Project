#include <iostream>
#include <memory>
#include "PopArr.h"
#include "stmt.h"

PopArr::PopArr() {}

std::unique_ptr<Stmt> PopArr::makePopArray(int x) {
    auto OP_POPARRAY = std::make_unique<Stmt>(x);
    return OP_POPARRAY;
}