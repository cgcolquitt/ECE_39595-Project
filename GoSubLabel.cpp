#include <iostream>
#include <memory>
#include "GoSubLabel.h"
#include "stmt.h"

GoSubLabel::GoSubLabel() {}

std::unique_ptr<Stmt> GoSubLabel::makeGoSubLabel(int x) {
    auto OP_ENTER_SUBROUTINE = std::make_unique<Stmt>(x);
    return OP_ENTER_SUBROUTINE;
}