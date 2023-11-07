#include <iostream>
#include <sstream>
#include "IntegerGetter.h"

IntGet::IntGet() {}

int IntGet::IntGetter(std::string statement) {
    std::stringstream ss;
    ss << statement;
    std::string temp;
    int found;
    while (!ss.eof()) {
        ss >> temp;
        if (std::stringstream(temp) >> found) {
            return found;
        }
        temp = "";
    }
    return 0;
}