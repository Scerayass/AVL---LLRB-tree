#ifndef FOURTHASSIGNMENT_MODELCOMMON_H
#define FOURTHASSIGNMENT_MODELCOMMON_H


#include "Model1.h"
#include "Model2.h"
#include <vector>
#include <fstream>
#include "Nodes.h"

class ModelCommon {
public:
    ofstream outputFile;
    primaryNode* head;
    Model1* model1;
    Model2* model2;
    void insert(vector<string> vector);
    primaryNode* findBST(primaryNode* head,string name);

    void remove(vector<string> vector);
    void printAllItems(primaryNode* head);
    void printAllItems222(primaryNode* head);
    void printSecondaries(secondaryNode* node);
    void printSecondaries222(secondaryNode* node);
    void printAllItemsInCategory(primaryNode* head,string nodeString);
    void printItem(primaryNode* head , string primaryString , string secondaryString);
    void find(primaryNode* head , string primaryString , string secondaryString);
    void updateData(primaryNode* head , string primaryString , string secondaryString , int updatedData);
    secondaryNode* findSecondary(secondaryNode* head,string name);
};


#endif //FOURTHASSIGNMENT_MODELCOMMON_H
