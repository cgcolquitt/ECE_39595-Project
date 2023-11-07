#ifndef POP_H_
#define POP_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Pop : public Stmt {
public:
    Pop();
    std::unique_ptr<Stmt> makePop(int x);
};

#endif /* POP_H_ */