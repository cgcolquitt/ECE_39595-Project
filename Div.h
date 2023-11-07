#ifndef DIV_H_
#define DIV_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Div : public Stmt {
public:
    Div();
    std::unique_ptr<Stmt> makeDiv(int x);
};

#endif /* DIV_H_ */