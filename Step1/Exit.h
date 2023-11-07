#ifndef EXIT_H_
#define EXIT_H_
#include <iostream>
#include <memory>
#include "stmt.h"

class Exit : public Stmt {
public:
    Exit();
    std::unique_ptr<Stmt> makeExit(int x);
};

#endif /* EXIT_H_ */