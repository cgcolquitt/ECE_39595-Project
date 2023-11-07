#ifndef NEGATE_H_
#define NEGATE_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Negate : public Stmt {
public:
    Negate();
    std::unique_ptr<Stmt> makeNegate(int x);
};

#endif /* NEGATE_H_ */