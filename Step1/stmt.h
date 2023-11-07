#ifndef STMT_H_
#define STMT_H_
#include <iostream>

class Stmt {
public:
    Stmt();
    Stmt(int numofvars);
    int VarNum;
};

#endif /* STMT_H_ */