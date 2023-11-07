#ifndef END_H_
#define END_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class End : public Stmt {
public:
    End();
    std::unique_ptr<Stmt> makeEnd(int x);
};

#endif /* END_H_ */