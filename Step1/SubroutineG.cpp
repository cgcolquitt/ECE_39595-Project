#include "SubroutineG.h"
#include <iostream>
#include <fstream>
#include <string>
#include "IntegerGetter.h"

SubroutineG::SubroutineG() {} 

int SubroutineG::SubroutineGetter(std::string infile) {
    int gsubsize = 0;
    IntGet obj;
    std::string state;
    std::fstream parsfile;
    parsfile.open(infile, std::ios::in);
    while(getline(parsfile, state)) {
        if(state.find("gosublabel") != std::string::npos) {
            std::string state2;
            while(getline(parsfile, state2)) {
                if(state2.find("declscal ") != std::string::npos) {
                    gsubsize = gsubsize + 1;
                }
                else if(state2.find("declarr ") != std::string::npos) {
                    gsubsize = gsubsize + obj.IntGetter(state2);
                }
                if(state2 == "return") {
                    break;
                }
            }
        }
    }
    parsfile.close();
    return gsubsize;
}