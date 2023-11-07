#ifndef PUSHSCAL_H_
#define PUSHSCAL_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class PushScal : public Stmt {
public:
    PushScal();
    std::unique_ptr<Stmt> makePushScal(int x);
};

#endif /* PUSHSCAl_H_ */