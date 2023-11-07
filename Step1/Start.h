#ifndef START_H_
#define START_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Start : public Stmt {
public:
    Start();
    std::unique_ptr<Stmt> makeStart(int x);
};

#endif /* START_H_ */