#ifndef FOURTHASSIGNMENT_MODELCOMMON_H
#define FOURTHASSIGNMENT_MODELCOMMON_H


#include "Model1.h"
#include "Model2.h"
#include <vector>
#include <fstream>
#include "Nodes.h"

class ModelCommon {
public:
    ofstream outputFile1;
    ofstream outputFile2;
    primaryNode* head;
    Model1* model1;
    Model2* model2;
    void insert(vector<string> vector);
    primaryNode* findBST(primaryNode* head,string name);

    void remove(vector<string> vector);
    void printAllItems(primaryNode* head , ofstream & outputFile ,int ModelNumber);
    void printAllItems222(primaryNode* head);
    void printSecondaries(secondaryNode* node,ofstream &outputFile);
    void printSecondaries222(secondaryNode* node);
    void printAllItemsInCategory(primaryNode* head,string nodeString,ofstream &outputFile, int modelNumber);
    void printItem(primaryNode* head , string primaryString , string secondaryString,ofstream &outputFile , int modelNumber);
    void find(primaryNode* head , string primaryString , string secondaryString,ofstream &outputFile);
    void updateData(primaryNode* head , string primaryString , string secondaryString , int updatedData);
    secondaryNode* findSecondary(secondaryNode* head,string name);
};


#endif //FOURTHASSIGNMENT_MODELCOMMON_H
