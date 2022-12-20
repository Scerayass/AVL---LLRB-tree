#include "ReadAndWriteFile.h"
#include <fstream>
#include <iostream>
#include "sstream"
#include <vector>
#include "Model2.h"
#include "ModelCommon.h"
#include "Model1.h"
#include <algorithm>

using namespace std;
void ReadAndWriteFile::execute() {
    string sadettin = "sadettin";
    const char* x = sadettin.c_str();
    char* y = "ahmet";
    if(lexicographical_compare(x,x + 100 , y, y + 100)){
        //cout << y; // sadettin lexicographically daha büyük
    }else{
        //cout << x;
    }
    ifstream inputFile("input.txt",ios::in);
    string inputString;

    Model1* model1 = new Model1();
    Model2* model2 = new Model2();

    ModelCommon* modelCommon = new ModelCommon();
    modelCommon->model1 = model1;
    modelCommon->model2 = model2;

    while(getline(inputFile,inputString)){

        string innerString;
        istringstream innerStream(inputString);
        vector<string> tempVector;

        while(getline(innerStream , innerString,'\t')) {
            tempVector.push_back(innerString);
        }
        if( tempVector.at(0) == "insert"){

            modelCommon->insert(tempVector);

        }else if(tempVector.at(0) == "remove"){

        }else if( tempVector.at(0) == "printAllItems"){

        }else if( tempVector.at(0) == "printAllItemsInCategory"){

        }else if( tempVector.at(0) == "printItem"){

        }else if( tempVector.at(0) == "find"){

        }else if ( tempVector.at(0) == "updateData"){

        }
    }
    modelCommon->printAllItems(modelCommon->head);
    modelCommon->printSecondaries(modelCommon->head->left->left->model2Secondary);
    inputFile.close();
}
