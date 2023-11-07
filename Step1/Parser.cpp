#include <iostream>
#include <fstream>
#include <memory>
#include <cctype>
#include <bits/stdc++.h>
#include "Parser.h"
#include "Start.h"
#include "Exit.h"
#include "End.h"
#include "PushI.h"
#include "IntegerGetter.h"
#include "Printtos.h"
#include "Add.h"
#include "Prints.h"
#include "Div.h"
#include "Dup.h"
#include "Mul.h"
#include "Negate.h"
#include "Pop.h"
#include "Swap.h"
#include "symboltable.h"
#include "DoubleStruct.h"
#include "Jump.h"
#include "GoSub.h"
#include "LabelGetter.h"
#include "GoSubLabel.h"
#include "SubroutineG.h"
#include "Return.h"
#include "PopScal.h"
#include "ScalGetter.h"
#include "PushScal.h"
#include "StartGetter.h"
#include "PopArr.h"
#include "ArrGetter.h"
#include "PushArr.h"
#include "JumpZero.h"
#include "JumpSub.h"
#include "JumpNZero.h"
#include "GoSubGetter.h"

void Parser::symbolTable(std::string infile) {
    std::string state;
    std::string temp;
    std::fstream parsfile;
    double storage = 0;
    Double loclen;
    double ind = 0;
    parsfile.open(infile, std::ios::in);
    while(getline(parsfile, state)) {
        if ((state.find("label ") != std::string::npos) && !(state.find("gosublabel ") != std::string::npos)) {
            SymbolTable obj;
            LabelGet obj1;
            std::string dummy;
            dummy = "label ";
            temp = state.erase(0, 6);
            double x = obj1.LabelGetter(infile, dummy, 7, temp);
            loclen = {x, 0};
            obj.createSymbolTable(temp, loclen);
        }
        else if (state.find("gosublabel ") != std::string::npos) {
            SymbolTable obj1;
            GoSubGet obj2;
            std::string dummy;
            dummy = "gosublabel ";
            temp = state.erase(0, 11);
            double x = obj2.GoSubGetter(infile, dummy, 12);
            loclen = {x, 0};
            obj1.createSymbolTable(temp, loclen);
            while(getline(parsfile, state)) {
                if(state == "return") {
                    Map subobj;
                    subobj.SYMBOLmapSub.clear();
                    break;
                }
                else if(state.find("label ") != std::string::npos && !(state.find("gosublabel ") != std::string::npos)) {
                    SymbolTable subobj;
                    LabelGet subobj1;
                    std::string subdummy;
                    subdummy = "label ";
                    temp = state.erase(0, 6);
                    double y = subobj1.LabelGetter(infile, subdummy, 7, temp);
                    loclen = {y, 0};
                    subobj.createSymbolTableSub(temp, loclen);
                }
                else if(state.find("declscal ") != std::string::npos) {
                    SymbolTable subobj1;
                    temp = state.erase(0, 9);
                    if(ind < 1) {
                        loclen = {0, 1};
                        subobj1.createSymbolTableSub(temp, loclen);
                        ind = ind + 1;
                        storage = storage + 1;
                    }
                    else {
                        loclen = {storage, 1};
                        subobj1.createSymbolTableSub(temp, loclen);
                        ind = ind + 1;
                        storage = storage + 1;
                    }
                }
                else if(state.find("declarr ") != std::string::npos) {
                    SymbolTable subobj2;
                    IntGet obj;
                    temp = state.erase(0, 8);
                    if(ind < 1) {
                        double x = obj.IntGetter(state);
                        temp = state.erase(1, 3);
                        loclen = {0, x};
                        subobj2.createSymbolTableSub(temp, loclen);
                        ind = ind + 1;
                        storage = storage + x;
                    }
                    else {
                        double x = obj.IntGetter(state);
                        temp = state.erase(1, 3);
                        loclen = {storage, x};
                        subobj2.createSymbolTableSub(temp, loclen);
                        ind = ind + 1;
                        storage = storage + x;
                    }
                }
            }
        }
        else if(state.find("declscal ") != std::string::npos) {
            SymbolTable obj2;
            temp = state.erase(0, 9);
            if(ind < 1) {
                loclen = {0, 1};
                obj2.createSymbolTable(temp, loclen);
                ind = ind + 1;
                storage = storage + 1;
            }
            else {
                loclen = {storage, 1};
                obj2.createSymbolTable(temp, loclen);
                ind = ind + 1;
                storage = storage + 1;
            }
        }
        else if(state.find("declarr ") != std::string::npos) {
            SymbolTable obj3;
            IntGet obj;
            temp = state.erase(0, 8);
            if(ind < 1) {
                double x = obj.IntGetter(state);
                temp = state.erase(1, 3);
                loclen = {0, x};
                obj3.createSymbolTable(temp, loclen);
                ind = ind + 1;
                storage = storage + x;
            }
            else {
                double x = obj.IntGetter(state);
                temp = state.erase(1, 3);
                loclen = {storage, x};
                obj3.createSymbolTable(temp, loclen);
                ind = ind + 1;
                storage = storage + x;
            }
        }
        
    }
    parsfile.close();    
}

void Parser::stringBuffer(std::string infile) {
    int index = 0;
    int filecount = 0;
    std::string state;
    std::fstream parsfile;
    parsfile.open(infile, std::ios::in);
    while(getline(parsfile, state)) {
        if (state.find("prints") != std::string::npos) {
            filecount = filecount + 1;
        }
    }
    parsfile.close();

    std::string stringBuffArray[filecount];

    std::string state1;
    std::fstream parsfile1;
    parsfile1.open(infile, std::ios::in);
    while(getline(parsfile1, state1)) {
        if (state1.find("prints") != std::string::npos) {
            size_t p = -1;
            std::string word = "prints";
            std::string temp = word + " ";
            while ((p = state1.find(word)) != std::string::npos) {
                state1.replace(p, temp.length(), "");
                stringBuffArray[index] = state1;
                index = index + 1;
            }
        }
    }
    parsfile1.close();

    int last = infile.length();
    int start = last - 4;
    infile.erase(start, last);
    infile = infile + ".out";
    std::fstream outfile;
    outfile.open(infile, std::ios::app);
    if(outfile.is_open()) {
        for(int i = 0; i < index; i++) {
            outfile << stringBuffArray[i] << std::endl;
        }
    }
}

void Parser::instructionBuffer(std::string infile) {
    int index = 0;
    int stringindex = 0;
    int filecount = 0;
    int varcount = 0;
    int printcount = 0;
    int gsub = 0;

    std::string state;
    std::fstream parsfile;
    parsfile.open(infile, std::ios::in);
    while(getline(parsfile, state)) {
        filecount = filecount + 1;
    }
    parsfile.close();

    std::unique_ptr<Stmt> insBuffArray[filecount];
    std::string stateArray[filecount];

    std::string state1;
    std::fstream parsfile2;
    parsfile2.open(infile, std::ios::in);
    while(getline(parsfile2, state1)) {
        if(state1 == "start") {
            Start obj; 
            StartGet obj1;
            int x = obj1.StartGetter(infile);
            insBuffArray[index] = obj.makeStart(x);
            stateArray[stringindex] = "Start";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "exit") {
            Exit obj;
            insBuffArray[index] = obj.makeExit(0);
            stateArray[stringindex] = "Exit";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("pushi") != std::string::npos) {
            IntGet obj;
            int num = obj.IntGetter(state1);
            PushI objP;
            insBuffArray[index] = objP.makePushI(num);
            stateArray[stringindex] = "PushI";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "printtos") {
            PrintTos obj;
            insBuffArray[index] = obj.makePrintTos(0);
            stateArray[stringindex] = "PrintTOS";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "add") {
            Add obj;
            insBuffArray[index] = obj.makeAdd(0);
            stateArray[stringindex] = "Add";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("prints") != std::string::npos) {
            Prints obj;
            insBuffArray[index] = obj.makePrints(printcount);
            stateArray[stringindex] = "Prints";
            index = index + 1;
            stringindex = stringindex + 1;
            printcount = printcount + 1;
        }
        else if(state1 == "div") {
            Div obj;
            insBuffArray[index] = obj.makeDiv(0);
            stateArray[stringindex] = "Div";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "dup") {
            Dup obj;
            insBuffArray[index] = obj.makeDup(0);
            stateArray[stringindex] = "Dup";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "mul") {
            Mul obj;
            insBuffArray[index] = obj.makeMul(0);
            stateArray[stringindex] = "Mul";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "negate") {
            Negate obj;
            insBuffArray[index] = obj.makeNegate(0);
            stateArray[stringindex] = "Negate";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "pop") {
            Pop obj;
            insBuffArray[index] = obj.makePop(0);
            stateArray[stringindex] = "Pop";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "swap") {
            Swap obj;
            insBuffArray[index] = obj.makeSwap(0);
            stateArray[stringindex] = "Swap";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("jump ") != std::string::npos) {
            Jump obj;
            LabelGet obj1;
            JumpSub obj2;
            int a;
            std::string temp;
            std::string word = "jump ";
            if(gsub == 1) {
                temp = state1.erase(0, 5);
                a = obj2.JumpSubGetter(infile, word, 6, temp);
            }
            else {
                temp = state1.erase(0, 5);
                a = obj1.LabelGetter(infile, word, 6, temp);
            }
            insBuffArray[index] = obj.makeJump(a);
            stateArray[stringindex] = "Jump";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("gosub ") != std::string::npos) {
            GoSub obj;
            GoSubGet obj1;
            std::string word = "gosub ";
            int a = obj1.GoSubGetter(infile, word, 7);
            insBuffArray[index] = obj.makeGoSub(a);
            stateArray[stringindex] = "GoSub";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("gosublabel") != std::string::npos) {
            GoSubLabel obj;
            SubroutineG obj1;
            int x = obj1.SubroutineGetter(infile);
            insBuffArray[index] = obj.makeGoSubLabel(x);
            stateArray[stringindex] = "GoSubLabel";
            index = index + 1;
            stringindex = stringindex + 1;
            gsub = 1;
        }
        else if(state1 == "return") {
            Return obj;
            insBuffArray[index] = obj.makeReturn(0);
            stateArray[stringindex] = "Return";
            index = index + 1;
            stringindex = stringindex + 1;
            gsub = 0;
        }
        else if(state1.find("popscal ") != std::string::npos) {
            PopScal obj;
            ScalGet obj1;
            std::string word = state1.erase(0, 8);
            int x = obj1.ScalGetter(infile, word, gsub);
            insBuffArray[index] = obj.makePopScal(x);
            stateArray[stringindex] = "PopScalar";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("pushscal ") != std::string::npos) {
            PushScal obj;
            ScalGet obj1;
            std::string word = state1.erase(0, 9);
            int x = obj1.ScalGetter(infile, word, gsub);
            insBuffArray[index] = obj.makePushScal(x);
            stateArray[stringindex] = "PushScalar";
            index = index + 1;
            stringindex = stringindex + 1; 
        }
        else if(state1.find("poparr ") != std::string::npos) {
            PopArr obj;
            ArrGet obj1;
            std::string word = state1.erase(0, 7);
            int x = obj1.ArrGetter(infile, word, gsub);
            insBuffArray[index] = obj.makePopArray(x);
            stateArray[stringindex] = "PopArray";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("pusharr ") != std::string::npos) {
            PushArr obj;
            ArrGet obj1;
            std::string word = state1.erase(0, 8);
            int x = obj1.ArrGetter(infile, word, gsub);
            insBuffArray[index] = obj.makePushArray(x);
            stateArray[stringindex] = "PushArray";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("jumpzero ") != std::string::npos) {
            JumpZero obj;
            LabelGet obj1;
            JumpSub obj2;
            int a;
            std::string temp;
            std::string word = "jumpzero ";
            if(gsub == 1) {
                temp = state1.erase(0, 9);
                a = obj2.JumpSubGetter(infile, word, 10, temp);
            }
            else {
                temp = state1.erase(0, 9);
                a = obj1.LabelGetter(infile, word, 10, temp);
            }
            insBuffArray[index] = obj.makeJumpZero(a);
            stateArray[stringindex] = "JumpZero";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1.find("jumpnzero ") != std::string::npos) {
            JumpNZero obj;
            LabelGet obj1;
            JumpSub obj2;
            int a;
            std::string temp;
            std::string word = "jumpnzero ";
            if(gsub == 1) {
                temp = state1.erase(0, 10);
                a = obj2.JumpSubGetter(infile, word, 11, temp);
            }
            else {
                temp = state1.erase(0, 10);
                a = obj1.LabelGetter(infile, word, 11, temp);
            }
            insBuffArray[index] = obj.makeJumpNZero(a);
            stateArray[stringindex] = "JumpNZero";
            index = index + 1;
            stringindex = stringindex + 1;
        }
        else if(state1 == "end") {
            End obj;
            insBuffArray[index] = obj.makeEnd(0);
            break;
        }
    }
    parsfile2.close();

    int last = infile.length();
    int start = last - 4;
    infile.erase(start, last);
    infile = infile + ".out";
    std::fstream outfile;
    outfile.open(infile, std::ios::app);
    if(outfile.is_open()) {
        for (int i = 0; i < filecount; i++) {
            if (stateArray[i] == "Exit") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "PrintTOS") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Add") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Div") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Dup") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Mul") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Negate") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Pop") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Swap") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "Return") {
                outfile << stateArray[i] << std::endl;
            }
            else if (stateArray[i] == "") {
                break;
            }
            else {
                outfile << stateArray[i] << " " << insBuffArray[i]->VarNum << std::endl;
            }
        }
    }
}
