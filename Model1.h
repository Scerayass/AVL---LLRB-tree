#ifndef FOURTHASSIGNMENT_MODEL1_H
#define FOURTHASSIGNMENT_MODEL1_H
#include <vector>
#include <string>
#include "Nodes.h"
using namespace std;

class Model1 {
public:
    primaryNode* head ;
    void insert(primaryNode* head, secondaryNode* newNode);
};


#endif //FOURTHASSIGNMENT_MODEL1_H
