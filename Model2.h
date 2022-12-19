#ifndef FOURTHASSIGNMENT_MODEL2_H
#define FOURTHASSIGNMENT_MODEL2_H
#include <vector>
#include <string>
#include "Nodes.h"
using namespace std;


class Model2 {
public:
    primaryNode* head ;
    void insert(primaryNode* head, secondaryNode* newNode);
};


#endif //FOURTHASSIGNMENT_MODEL2_H
