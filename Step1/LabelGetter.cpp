#include <iostream>
#include <fstream>
#include <string>
#include "LabelGetter.h"

LabelGet::LabelGet() {}

int LabelGet::LabelGetter(std::string infile, std::string word, int wordlength, std::string label) {
    int number = 0;
    std::string dummy;
    std::string state;
    std::fstream file;
    file.open(infile, std::ios::in);
    while(getline(file, state)) {
        if(state.find(word + label) != std::string::npos) {
            dummy = state.erase(0, wordlength - 1);
            break;
        }
    }
    file.close();
    std::string state1;
    std::fstream file1;
    int counter = 0;
    file1.open(infile, std::ios::in);
    while(getline(file1, state1)) {
        number = number + 1;
        if(state1.find("declscal ") != std::string::npos) {
            number = number - 1;
        }
        else if(state1.find("declarr ") != std::string::npos) {
            number = number - 1;
        }
        else if(state1.find("label ") != std::string::npos && state1.find("gosublabel ") == std::string::npos) {
            if(state1 == "label " + dummy) {
                return number - 1;
            }
            else {
                number = number - 1;
            }
        }
        else if(state1.find("gosublabel ") != std::string::npos) {
            std::string state2;
            while(getline(file1, state2)) {
                number = number + 1;
                if(state2.find("declscal ") != std::string::npos) {
                    number = number - 1;
                }
                else if(state2.find("declarr ") != std::string::npos) {
                    number = number - 1;
                }
                else if(state2.find("label ") != std::string::npos) {
                    number = number - 1;
                }
                else if(state2.find("return") != std::string::npos) {
                    break;
                }
            }
        }
    }
    file1.close();
    return 0;
}