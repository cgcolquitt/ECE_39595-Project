#ifndef GOSUBLABEL_H_
#define GOSUBLABEL_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class GoSubLabel : public Stmt {
public:
    GoSubLabel();
    std::unique_ptr<Stmt> makeGoSubLabel(int x);
};

#endif /* GOSUBLABEL_H_ */