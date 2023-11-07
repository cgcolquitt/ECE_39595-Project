#ifndef RETURN_H_
#define RETURN_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Return : public Stmt {
public:
    Return();
    std::unique_ptr<Stmt> makeReturn(int x);
};

#endif /* RETURN_H_ */