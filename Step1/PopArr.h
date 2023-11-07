#ifndef POPARR_H_
#define POPARR_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class PopArr : public Stmt {
public:
    PopArr();
    std::unique_ptr<Stmt> makePopArray(int x);
};

#endif /* POPARR_H_ */