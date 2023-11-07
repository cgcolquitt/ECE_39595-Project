#ifndef JUMP_H_
#define JUMP_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Jump : public Stmt {
public:
    Jump();
    std::unique_ptr<Stmt> makeJump(int x);
};

#endif /* START_H_ */