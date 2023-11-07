#include <iostream>
#include <fstream>
#include <string>
#include "ArrGetter.h"
#include "IntegerGetter.h"

ArrGet::ArrGet() {}

int ArrGet::ArrGetter(std::string infile, std::string word, int gsub) {
    int number = 0;
    int varnum = 0;
    int num = 0;
    int idx = 0;
    int dummy = 0;
    IntGet obj;
    std::string state0;
    std::fstream file0; 
    file0.open(infile, std::ios::in);
    while(getline(file0, state0)) {
        if(state0.find("declarr ") != std::string::npos) {
            idx = idx + 1;
            dummy = dummy + obj.IntGetter(state0);
            if(idx == 1 && state0.find("declarr ") != std::string::npos) {
                varnum = 0;
            }
            else if(idx > 1 && state0.find("declarr ") != std::string::npos) {
                varnum = varnum + dummy;
            }
        }
        else if(state0.find("declscal ") != std::string::npos) {
            varnum = varnum + 1;
        }
        else if(state0.find("gosublabel ") != std::string::npos) {
            break;
        }
    }
    file0.close();
    std::string state;
    std::fstream file;
    int count = 0;
    int temp = 0;
    file.open(infile, std::ios::in);
    if(gsub == 1) {
        while(getline(file, state)) {
            if(state.find("gosublabel ") != std::string::npos) {
                std::string state2;
                while(getline(file, state2)) {
                    if(state2.find("declarr ") != std::string::npos) {
                        count = count + 1;
                        if(count == 1 && state2.find("declarr " + word) != std::string::npos) {
                            varnum = 0 + varnum;
                        }
                        else if(count > 1 && state2.find("declarr " + word) != std::string::npos) {
                            varnum = varnum + temp;
                        }
                        temp = temp + obj.IntGetter(state2);
                    }
                }
            }
        }
        return varnum;
    }
    else {
        while(getline(file, state)) {
            if(state.find("declarr ") != std::string::npos) {
                count = count + 1;
                if(count == 1 && state.find("declarr " + word) != std::string::npos) {
                    num = 0;
                    return num;
                }
                else if(count > 1 && state.find("declarr " + word) != std::string::npos) {
                    num = num + temp;
                    return num;
                }
                temp = temp + obj.IntGetter(state);
            }
            else if(state.find("declscal ") != std::string::npos) {
                num = num + 1;
            }
        }
    }
    file.close();
    return 0;
}