#ifndef GOSUB_H_
#define GOSUB_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class GoSub : public Stmt {
public:
    GoSub();
    std::unique_ptr<Stmt> makeGoSub(int x);
};

#endif /* GOSUB_H_ */