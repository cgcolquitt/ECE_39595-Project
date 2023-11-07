#ifndef PUSHI_H_
#define PUSHI_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class PushI : public Stmt {
public:
    PushI();
    std::unique_ptr<Stmt> makePushI(int x);
};

#endif /* PUSHI_H_ */