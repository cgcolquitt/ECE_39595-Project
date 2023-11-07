#include <iostream>
#include <fstream>
#include "scanner.h"
#include "LabelGetter.h"
#include <array>

int Scanner::scanfile(std::string infile) {
    int i = 0;
    int filesize = 0;
    std::string statement;
    std::fstream checkfile;
    checkfile.open(infile, std::ios::in);
    while(getline(checkfile, statement)) {
        filesize = filesize + 1;
    }
    checkfile.close();

    std::string filetobescanned[filesize];
    std::string statement1;
    std::fstream checkfile1;
    checkfile1.open(infile, std::ios::in);
    while(getline(checkfile1, statement1)) {
        filetobescanned[i] = statement1;
        i++;
    }
    checkfile1.close();

    int temp = 0;
    int endmark = 0;
    std::string hold;
    for(int x = 0; x < filesize; x++) {
        if(filetobescanned[x].find("end") != std::string::npos) {
            temp = 1;
            endmark = x;
        }
        else if(filetobescanned[x].find("declscal") != std::string::npos) {
            hold = filetobescanned[x];
            int z = x;
            while(filetobescanned[z].find("gosub") == std::string::npos && z < filesize) {
                z = z + 1;
                if(filetobescanned[z] == hold) {
                    hold.erase(0,9);
                    std::cout << "error: attempting to add variable with name " << hold << " twice" << std::endl;
                    return 0;
                }
            }
        }
        else if(filetobescanned[x].find("declarr") != std::string::npos) {
            hold = filetobescanned[x];
            int z = x;
            while(filetobescanned[z].find("gosub") == std::string::npos && z < filesize) {
                z = z + 1;
                if(filetobescanned[z] == hold) {
                    hold.erase(0,8);
                    hold.erase(1,3);
                    std::cout << "error: attempting to add variable with name " << hold << " twice" << std::endl;
                    return 0;
                }
            }
        }
        else if(filetobescanned[x].find("label") != std::string::npos && filetobescanned[x].find("gosublabel") == std::string::npos) {
            hold = filetobescanned[x];
            int z = x;
            while(filetobescanned[z].find("end") == std::string::npos) {
                z = z + 1;
                if(filetobescanned[z] == hold) {
                    hold.erase(0,6);
                    std::cout << "error: attempting to add label with name " << hold << " twice" << std::endl;
                    return 0;
                }
            }
        }
    } 
    if(temp == 0) {
        std::cout << "error: no end statement in program" << std::endl;
        return 0;
    }
    else {
        if(filetobescanned[endmark + 1] != "") {
            std::cout << "error: code encountered after an end statement" << std::endl;
            return 0;
        }
    }
    return 1;
}