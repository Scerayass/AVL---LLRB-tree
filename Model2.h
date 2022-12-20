#ifndef FOURTHASSIGNMENT_MODEL2_H
#define FOURTHASSIGNMENT_MODEL2_H
#include <vector>
#include <string>
#include "Nodes.h"
using namespace std;


class Model2 {
public:
    primaryNode* head ;
    secondaryNode* insert(primaryNode *head, secondaryNode * secondaryHead ,  string nodeName, int nodeData);
    secondaryNode* rotateLeft(secondaryNode* node);
    secondaryNode* rotateRight(secondaryNode* node);
    void changeColors(secondaryNode* firstNode,secondaryNode* secondNode);

};


#endif //FOURTHASSIGNMENT_MODEL2_H
