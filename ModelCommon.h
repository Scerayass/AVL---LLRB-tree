#ifndef FOURTHASSIGNMENT_MODELCOMMON_H
#define FOURTHASSIGNMENT_MODELCOMMON_H


#include "Model1.h"
#include "Model2.h"
#include <vector>
#include "Nodes.h"

class ModelCommon {
public:
    primaryNode* head;
    Model1* model1;
    Model2* model2;
    void insert(vector<string> vector);
    primaryNode* findBST(primaryNode* head,string name,string location,string type);
    primaryNode* remove(vector<string> vector);
    void printAllItems(primaryNode* head);
};


#endif //FOURTHASSIGNMENT_MODELCOMMON_H
