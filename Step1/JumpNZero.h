#ifndef JUMPNZERO_H_
#define JUMPNZERO_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class JumpNZero : public Stmt {
public:
    JumpNZero();
    std::unique_ptr<Stmt> makeJumpNZero(int x);
};

#endif /* JUMPNZERO_H_ */