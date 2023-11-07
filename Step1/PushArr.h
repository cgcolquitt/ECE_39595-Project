#ifndef PUSHARR_H_
#define PUSHARR_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class PushArr : public Stmt {
public:
    PushArr();
    std::unique_ptr<Stmt> makePushArray(int x);
};

#endif /* PUSHARRAY_H_ */