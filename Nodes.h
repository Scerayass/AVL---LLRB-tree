#ifndef FOURTHASSIGNMENT_NODES_H
#define FOURTHASSIGNMENT_NODES_H

struct secondaryNode;
using namespace std;
struct primaryNode{
    int height;
    std::string name;
    primaryNode* left;
    primaryNode* right;
    secondaryNode* model1Secondary;
    secondaryNode* model2Secondary;

    primaryNode(std::string nodeName){
        left = NULL;
        right = NULL;
        name = nodeName;
    }

};
struct secondaryNode{
    int height;
    int data;
    bool color;

    std::string name;
    secondaryNode* left;
    secondaryNode* right;
    secondaryNode(string nodeName, int nodeData){
        left = NULL;
        right = NULL;
        color = true;
        name = nodeName;
        data = nodeData;
    }
};


#endif //FOURTHASSIGNMENT_NODES_H
