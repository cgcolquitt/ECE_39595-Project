#include <iostream>
#include <memory>
#include "End.h"
#include "stmt.h"

End::End() {}

std::unique_ptr<Stmt> End::makeEnd(int x) {
    auto end_program = std::make_unique<Stmt>(x);
    return end_program;
}