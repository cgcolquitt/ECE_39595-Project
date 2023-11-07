#ifndef DUP_H_
#define DUP_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Dup : public Stmt {
public:
    Dup();
    std::unique_ptr<Stmt> makeDup(int x);
};

#endif /* START_H_ */