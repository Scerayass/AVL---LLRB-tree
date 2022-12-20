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
void ReadAndWriteFile::execute(string inputFileName,string outputFileName) {

    ifstream inputFile(inputFileName,ios::in);

    string inputString;

    Model1* model1 = new Model1();
    Model2* model2 = new Model2();

    ModelCommon* modelCommon = new ModelCommon();
    modelCommon->outputFile.open(outputFileName , ios::out);
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
            modelCommon->remove(tempVector);
        }else if( tempVector.at(0) == "printAllItems"){
            modelCommon->printAllItems(modelCommon->head);
        }else if( tempVector.at(0) == "printAllItemsInCategory"){
            modelCommon->printAllItemsInCategory(modelCommon->head,tempVector.at(1));
        }else if( tempVector.at(0) == "printItem"){
            modelCommon->printItem(modelCommon->head,tempVector.at(1),tempVector.at(2));
        }else if( tempVector.at(0) == "find"){
            modelCommon->find(modelCommon->head , tempVector.at(1),tempVector.at(2));
        }else if ( tempVector.at(0) == "updateData"){
            modelCommon->updateData(modelCommon->head,tempVector.at(1),tempVector.at(2), stoi(tempVector.at(3)));
        }
    }
    modelCommon->printAllItems222(modelCommon->head);
    //modelCommon->printSecondaries(modelCommon->head->left->left->model2Secondary);
    inputFile.close();
}
