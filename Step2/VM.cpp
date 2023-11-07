#include <iostream>
#include <fstream>
#include <memory>
#include <stack>
#include "VM.h"
#include "IntegerGetter.h"
#include <vector>

void VirtualMachine::VMexecution(char *infile) {
    std::stack<int> runtimestack;
    std::stack<int> returnaddress;
    std::vector<int> datamemoryS;
    std::vector<int> datamemoryG;
    int pc = 0;
    int filesize = 0;
    int stringnum = 0;
    IntGet obj;
    std::string instruction;
    std::fstream executevm;
    executevm.open(infile, std::ios::in);
    while(getline(executevm, instruction)) {
        stringnum = stringnum + 1;
        if(instruction.find("Start") != std::string::npos) {
            filesize = filesize + 1;
            while(getline(executevm, instruction)) {
                filesize = filesize + 1;
            }
        }
    }
    executevm.close();

    std::string VMfile[filesize + 1];
    std::string stringbuff[stringnum + 1];
    std::string instruction1;
    std::fstream loadinstructions;
    int index = 0;
    loadinstructions.open(infile, std::ios::in);
    while(getline(loadinstructions, instruction1)) {
        stringbuff[index] = instruction1;
        index++;
        if(instruction1.find("Start") != std::string::npos) {
            VMfile[pc] = instruction1;
            pc++;
            while(getline(loadinstructions, instruction1)) {
                VMfile[pc] = instruction1;
                pc++;
            }
        }
    }
    loadinstructions.close();

    int i = 0;
    int sub = 0;
    int gsubrecurse = 0;
    int subcount = 0;
    while(i <= filesize) {
        if(VMfile[i].find("Start") != std::string::npos) {
            int a = obj.IntGetter(VMfile[i]);
            for(int i = 0; i < a; i++) {
                datamemoryS.push_back(0);
            }
        }
        else if(VMfile[i].find("PushI") != std::string::npos) {
            runtimestack.push(obj.IntGetter(VMfile[i]));
        }
        else if(VMfile[i].find("Jump") != std::string::npos && VMfile[i].find("JumpZero") == std::string::npos && VMfile[i].find("JumpNZero") == std::string::npos) {
            i = obj.IntGetter(VMfile[i]) - 1;
        }
        else if(VMfile[i].find("JumpZero") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            if(a == 0) {
                i = obj.IntGetter(VMfile[i]) - 1;
            }
        }
        else if(VMfile[i].find("JumpNZero") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            if(a != 0) {
                i = obj.IntGetter(VMfile[i]) - 1;
            }
        }
        else if(VMfile[i].find("PopScalar") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            int b = obj.IntGetter(VMfile[i]);
            if(datamemoryG.size() < b + gsubrecurse) {
                for(int i = 0; i < (b + gsubrecurse); i++) {
                    datamemoryG.push_back(0);
                }
            }
            if(sub == 1) {
                datamemoryG[b + gsubrecurse] = a;
            }
            else {
                datamemoryS[b] = a;  
            }
        }
        else if(VMfile[i].find("PopArray") != std::string::npos) {
            int e = runtimestack.top() + obj.IntGetter(VMfile[i]);
            runtimestack.pop();
            int a = runtimestack.top();
            runtimestack.pop();
            if(datamemoryG.size() < e + gsubrecurse) {
                for(int i = 0; i < (e + gsubrecurse); i++) {
                    datamemoryG.push_back(0);
                }
            }
            if(sub == 1) {
                datamemoryG[e + gsubrecurse] = a;
            }
            else {
                datamemoryS[e] = a;
            }
        }
        else if(VMfile[i].find("Prints") != std::string::npos) {
            std::cout << stringbuff[obj.IntGetter(VMfile[i])] << std::endl;
        }
        else if(VMfile[i].find("GoSub") != std::string::npos && VMfile[i].find("GoSubLabel") == std::string::npos) {
            subcount = subcount + 1;
            returnaddress.push(i + 1);
            i = obj.IntGetter(VMfile[i]) - 1;
            if(subcount > 1) {
                gsubrecurse = gsubrecurse + 1;
            }
        }
        else if(VMfile[i].find("GoSubLabel") != std::string::npos) {
            int a = obj.IntGetter(VMfile[i]);
            for(int i = 0; i < a; i++) {
                datamemoryG.push_back(0);
            }
            sub = 1;
        }
        else if(VMfile[i].find("PushScalar") != std::string::npos) {
            if(sub == 1) {
                int a = datamemoryG[obj.IntGetter(VMfile[i]) + gsubrecurse];
                runtimestack.push(a);
            }
            else {
                int a = datamemoryS[obj.IntGetter(VMfile[i])];
                runtimestack.push(a);
            }
        }
        else if(VMfile[i].find("PushArray") != std::string::npos) {
            if(sub == 1) {
                int e = obj.IntGetter(VMfile[i]) + runtimestack.top();
                runtimestack.pop();
                runtimestack.push(datamemoryG[e] + gsubrecurse);
            }
            else {
                int e = obj.IntGetter(VMfile[i]) + runtimestack.top();
                runtimestack.pop();
                runtimestack.push(datamemoryS[e]);
            }
        }
        else if(VMfile[i].find("PrintTOS") != std::string::npos) {
            int a = runtimestack.top();
            std::cout << a << std::endl;
            runtimestack.pop();
        }
        else if(VMfile[i].find("Add") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            int b = runtimestack.top();
            runtimestack.pop();
            int c = a + b;
            runtimestack.push(c);
        }
        else if(VMfile[i].find("Div") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            int b = runtimestack.top();
            runtimestack.pop();
            int c = a / b;
            runtimestack.push(c);
        }
        else if(VMfile[i].find("Dup") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.push(a);
        }
        else if(VMfile[i].find("Mul") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            int b = runtimestack.top();
            runtimestack.pop();
            int c = a * b;
            runtimestack.push(c);
        }
        else if(VMfile[i].find("Negate") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            a = -a;
            runtimestack.push(a);
        }
        else if(VMfile[i].find("Pop") != std::string::npos && VMfile[i].find("PopScalar") == std::string::npos && VMfile[i].find("PopArray") == std::string::npos) {
            runtimestack.pop();
        }
        else if(VMfile[i].find("Swap") != std::string::npos) {
            int a = runtimestack.top();
            runtimestack.pop();
            int b = runtimestack.top();
            runtimestack.pop();
            runtimestack.push(a);
            runtimestack.push(b);
        }
        else if(VMfile[i].find("Return") != std::string::npos) {
            gsubrecurse = gsubrecurse - 1;
            i = returnaddress.top() - 1;
            returnaddress.pop();
            datamemoryG.pop_back();
            if(returnaddress.empty()) {
                sub = 0;
            }
            else {
                sub = 1;  
            }
        }
        i++;
    }
}
