#ifndef PRINTS_H_
#define PRINTS_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Prints : public Stmt {
public:
    Prints();
    std::unique_ptr<Stmt> makePrints(int x);
};

#endif /* PRINTS_H_ */