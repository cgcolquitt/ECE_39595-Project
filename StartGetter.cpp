#include <iostream>
#include <fstream>
#include <string>
#include "StartGetter.h"
#include "IntegerGetter.h"

StartGet::StartGet() {}

int StartGet::StartGetter(std::string infile) {
    int number = 0;
    int arrlen = 0;
    std::string state;
    std::fstream file;
    IntGet obj;
    file.open(infile, std::ios::in);
    while(getline(file, state)) {
        if(state.find("declscal ") != std::string::npos) {
            number = number + 1;
        }
        else if(state.find("gosublabel ") != std::string::npos) {
            break;
        }
        else if(state.find("declarr ") != std::string::npos) {
            arrlen = arrlen + obj.IntGetter(state);
        }
    }
    file.close();
    return number + arrlen;
}