#include <iostream>
#include <fstream>
#include <string>
#include "ScalGetter.h"
#include "IntegerGetter.h"

ScalGet::ScalGet() {}

int ScalGet::ScalGetter(std::string infile, std::string word, int gsub) {
    int number = 0;
    int varnum = -1;
    int num = -1;
    IntGet obj;
    std::string state0;
    std::fstream file0; 
    file0.open(infile, std::ios::in);
    while(getline(file0, state0)) {
        if(state0.find("declscal ") != std::string::npos) {
            varnum = varnum + 1;
        }
        if(state0.find("declarr ") != std::string::npos) {
            varnum = varnum + obj.IntGetter(state0);
        }
        if(state0.find("gosublabel ") != std::string::npos) {
            break;
        }
    }
    file0.close();

    std::string state;
    std::fstream file;
    file.open(infile, std::ios::in);
    if(gsub == 1) {
        while(getline(file, state)) {
            if(state.find("gosublabel ") != std::string::npos) {
                std::string state2;
                while(getline(file, state2)) {
                    if(state2.find("declscal ") != std::string::npos) {
                        number = number + 1;
                        if(state2.find("declscal " + word) != std::string::npos) {
                            return (number + varnum);
                        }
                    }
                    else if(state2.find("declarr ") != std::string::npos) {
                        number = number + obj.IntGetter(state2);
                    }
                }
            }
        }
    }
    else {
        while(getline(file, state)) {
            if(state.find("declscal ") != std::string::npos) {
                num = num + 1;
                if(state.find("declscal " + word) != std::string::npos) {
                    return num;
                }
            }
            else if(state.find("declarr ") != std::string::npos) {
                num = num + obj.IntGetter(state);
            }
        }
    }
    file.close();
    return 0;
}