#ifndef FOURTHASSIGNMENT_MODEL2_H
#define FOURTHASSIGNMENT_MODEL2_H
#include <vector>
#include <string>
#include "Nodes.h"
using namespace std;


class Model2 {
public:
    primaryNode* head ;
    /**
     * insert a new node to tree
     * @param head
     * @param secondaryHead
     * @param nodeName
     * @param nodeData
     * @return
     */
    secondaryNode* insert(primaryNode *head, secondaryNode * secondaryHead ,  string nodeName, int nodeData);
    /**
     * rotates selected node to left
     * @param node
     * @return
     */
    secondaryNode* rotateLeft(secondaryNode* node);
    /**
     * rotates selected node to right
     * @param node
     * @return
     */
    secondaryNode* rotateRight(secondaryNode* node);
    /**
     * changes colors between two nodes
     * @param firstNode
     * @param secondNode
     */
    void changeColors(secondaryNode* firstNode,secondaryNode* secondNode);
    /**
     * removes selected nodes if exists
     * @param head
     * @param secondaryHead
     * @param nodeName
     * @return
     */
    secondaryNode* remove(primaryNode* head , secondaryNode* secondaryHead,string nodeName,string anotherNodenName);
    /**
     * finds the min value for selected value
     * @param head
     * @return
     */
    secondaryNode* findMin(secondaryNode* head);
    /**
     * deletes the min value for that node
     * @param head
     * @return
     */
    secondaryNode* deleteMin(secondaryNode* head);
    secondaryNode* moveRedRight(secondaryNode *head);
    secondaryNode* moveRedLeft(secondaryNode* head);
    bool isRed(secondaryNode* head);
};


#endif //FOURTHASSIGNMENT_MODEL2_H
