#ifndef ARRGETTER_H_
#define ARRGETTER_H_
#include <iostream>
#include <sstream>

class ArrGet {
public:
    ArrGet();
    int ArrGetter(std::string infile, std::string word, int gsub);
};

#endif /* ARRGETTER_H_ */