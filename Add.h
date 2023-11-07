#ifndef ADD_H_
#define ADD_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Add : public Stmt {
public:
    Add();
    std::unique_ptr<Stmt> makeAdd(int x);
};

#endif /* ADD_H_ */