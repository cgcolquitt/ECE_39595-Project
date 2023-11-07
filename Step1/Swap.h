#ifndef SWAP_H_
#define SWAP_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Swap : public Stmt {
public:
    Swap();
    std::unique_ptr<Stmt> makeSwap(int x);
};

#endif /* SWAP_H_ */