#ifndef FOURTHASSIGNMENT_NODES_H
#define FOURTHASSIGNMENT_NODES_H

struct secondaryNode;

struct primaryNode{
    int height;
    std::string name;
    primaryNode* left;
    primaryNode* right;
    secondaryNode* model1Secondary;
    secondaryNode* model2Secondary;

};
struct secondaryNode{
    int height;
    int data;
    bool color;

    std::string name;
    secondaryNode* left;
    secondaryNode* right;
};


#endif //FOURTHASSIGNMENT_NODES_H
