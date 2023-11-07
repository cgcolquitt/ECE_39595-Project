#ifndef GOSUBGETTER_H_
#define GOSUBGETTER_H_
#include <iostream>
#include <sstream>

class GoSubGet {
public:
    GoSubGet();
    int GoSubGetter(std::string infile, std::string word, int wordlength);
};

#endif /* GOSUBGETTER_H_ */