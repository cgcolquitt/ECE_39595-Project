#ifndef JUMPZERO_H_
#define JUMPZERO_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class JumpZero : public Stmt {
public:
    JumpZero();
    std::unique_ptr<Stmt> makeJumpZero(int x);
};

#endif /* JUMPZERO_H_ */