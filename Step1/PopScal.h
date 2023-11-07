#ifndef POPSCAL_H_
#define POPSCAL_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class PopScal : public Stmt {
public:
    PopScal();
    std::unique_ptr<Stmt> makePopScal(int x);
};

#endif /* POPSCAL_H_ */