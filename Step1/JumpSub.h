#ifndef JUMPSUB_H_
#define JUMPSUB_H_
#include <iostream>
#include <sstream>

class JumpSub {
public:
    JumpSub();
    int JumpSubGetter(std::string statement, std::string word, int wordlength, std::string label);
};

#endif /* JUMPSUB_H_ */