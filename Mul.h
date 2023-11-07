#ifndef MUL_H_
#define MUL_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Mul : public Stmt {
public:
    Mul();
    std::unique_ptr<Stmt> makeMul(int x);
};

#endif /* MUL_H_ */