#ifndef FOURTHASSIGNMENT_MODEL1_H
#define FOURTHASSIGNMENT_MODEL1_H
#include <vector>
#include <string>
#include "Nodes.h"
using namespace std;

class Model1 {
public:
    primaryNode* head ;
    int maxHeight(secondaryNode *node1 , secondaryNode* node2);
    int isBalanced(secondaryNode* node);
    secondaryNode* rotateRight(secondaryNode* node);
    secondaryNode* rotateLeft(secondaryNode* node);
    secondaryNode* insert(primaryNode* head, secondaryNode* secondaryHead , string nodeName, int nodeData);
};


#endif //FOURTHASSIGNMENT_MODEL1_H
