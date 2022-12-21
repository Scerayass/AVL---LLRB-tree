#include <iostream>
#include "ReadAndWriteFile.h"


int main() {
    ReadAndWriteFile file;
    file.execute("input.txt","output.txt","output2.txt");
    return 0;
}
