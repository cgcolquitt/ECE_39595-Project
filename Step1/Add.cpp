#include <iostream>
#include <memory>
#include "Add.h"
#include "stmt.h"

Add::Add() {}

std::unique_ptr<Stmt> Add::makeAdd(int x) {
    auto OP_ADD = std::make_unique<Stmt>(x);
    return OP_ADD;
}