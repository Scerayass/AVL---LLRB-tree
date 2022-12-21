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
void ReadAndWriteFile::execute(string inputFileName,string outputFileName1 , string outputFileName2) {

    ifstream inputFile(inputFileName,ios::in);

    string inputString;

    Model1* model1 = new Model1();
    Model2* model2 = new Model2();

    ModelCommon* modelCommon = new ModelCommon();
    modelCommon->outputFile1.open(outputFileName1 , ios::out);
    modelCommon->outputFile2.open(outputFileName2,ios::out);
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

            modelCommon->outputFile1 << "command:printAllItems\n{\n";
            modelCommon->outputFile2 << "command:printAllItems\n{\n";
            modelCommon->printAllItems(modelCommon->head , modelCommon->outputFile1 , 1);
            modelCommon->printAllItems(modelCommon->head , modelCommon->outputFile2 , 2);
            modelCommon->outputFile1 << "}\n";
            modelCommon->outputFile2 << "}\n";

        }else if( tempVector.at(0) == "printAllItemsInCategory"){

            modelCommon->outputFile1 << "command:printAllItemsInCategory " << tempVector.at(1) << "\n{\n";
            modelCommon->outputFile2 << "command:printAllItemsInCategory " << tempVector.at(1) << "\n{\n";
            modelCommon->printAllItemsInCategory(modelCommon->head,tempVector.at(1),modelCommon->outputFile1 , 1);
            modelCommon->printAllItemsInCategory(modelCommon->head,tempVector.at(1),modelCommon->outputFile2 , 2);
            modelCommon->outputFile1<< "}\n";
            modelCommon->outputFile2<< "}\n";

        }else if( tempVector.at(0) == "printItem"){

            modelCommon->outputFile1 << "command:printItem\t" << tempVector.at(1) << "\t" << tempVector.at(2) << "\n{" ;
            modelCommon->outputFile2 << "command:printItem\t" << tempVector.at(1) << "\t" << tempVector.at(2) << "\n{" ;
            modelCommon->printItem(modelCommon->head,tempVector.at(1),tempVector.at(2),modelCommon->outputFile1 , 1);
            modelCommon->printItem(modelCommon->head,tempVector.at(1),tempVector.at(2),modelCommon->outputFile2 , 2);
            modelCommon->outputFile1<< "}\n";
            modelCommon->outputFile2<< "}\n";
        }else if( tempVector.at(0) == "find"){

            modelCommon->outputFile1 << "command:find\t" << tempVector.at(1) << "\t" << tempVector.at(2) << "\n{" ;
            modelCommon->outputFile2 << "command:find\t" << tempVector.at(1) << "\t" << tempVector.at(2) << "\n{" ;
            modelCommon->printItem(modelCommon->head , tempVector.at(1),tempVector.at(2),modelCommon->outputFile1 , 1);
            modelCommon->printItem(modelCommon->head , tempVector.at(1),tempVector.at(2),modelCommon->outputFile2 , 2);
            modelCommon->outputFile1<< "}\n";
            modelCommon->outputFile2<< "}\n";
        }else if ( tempVector.at(0) == "updateData"){
            modelCommon->updateData(modelCommon->head,tempVector.at(1),tempVector.at(2), stoi(tempVector.at(3)));
        }
    }
    //modelCommon->printAllItems222(modelCommon->head);
    //modelCommon->printSecondaries(modelCommon->head->left->left->model2Secondary);
    modelCommon->outputFile2.close();
    modelCommon->outputFile1.close();
    inputFile.close();
}
