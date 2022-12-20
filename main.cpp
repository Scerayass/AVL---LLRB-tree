#include <iostream>
#include "ReadAndWriteFile.h"


int main() {
    ReadAndWriteFile file;
    file.execute("input.txt","output.txt");
    return 0;
}
