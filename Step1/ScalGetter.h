#ifndef SCALGETTER_H_
#define SCALGETTER_H_
#include <iostream>
#include <sstream>

class ScalGet {
public:
    ScalGet();
    int ScalGetter(std::string infile, std::string word, int gsub);
};

#endif /* SCALGETTER_H_ */