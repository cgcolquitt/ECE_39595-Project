#ifndef LABELGETTER_H_
#define LABELGETTER_H_
#include <iostream>
#include <sstream>

class LabelGet {
public:
    LabelGet();
    int LabelGetter(std::string infile, std::string word, int wordlength, std::string label);
};

#endif /* LABELGETTER_H_ */