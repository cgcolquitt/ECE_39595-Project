#ifndef PRINTTOS_H_
#define PRINTTOS_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class PrintTos : public Stmt {
public:
    PrintTos();
    std::unique_ptr<Stmt> makePrintTos(int x);
};

#endif /* PRINTTOS_H_ */