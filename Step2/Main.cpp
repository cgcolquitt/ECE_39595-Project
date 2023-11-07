#include <iostream>
#include <fstream>
#include <memory>
#include "VM.h"

int main(int argc, char ** argv) {
    VirtualMachine obj;
    obj.VMexecution(argv[1]);
    return EXIT_SUCCESS;
}

