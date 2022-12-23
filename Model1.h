#ifndef FOURTHASSIGNMENT_MODEL1_H
#define FOURTHASSIGNMENT_MODEL1_H
#include <vector>
#include <string>
#include "Nodes.h"
using namespace std;

class Model1 {
public:

    primaryNode* head ;
    /**
     * this function finds the maximum height of tree
     * @param node1
     * @param node2
     * @return
     */
    int maxHeight(secondaryNode *node1 , secondaryNode* node2);

    /**
     * this function check tree if it balanced or tree
     * @param node
     * @return
     */
    int isBalanced(secondaryNode* node);

    /**
     * rotates selected node to right
     * @param node
     * @return
     */
    secondaryNode* rotateRight(secondaryNode* node);

    /**
     * rotates selected node to left
     * @param node
     * @return
     */
    secondaryNode* rotateLeft(secondaryNode* node);
    /**
     * insert a new node to tree
     * @param head
     * @param secondaryHead
     * @param nodeName
     * @param nodeData
     * @return
     */
    secondaryNode* insert(primaryNode* head, secondaryNode* secondaryHead , string nodeName, int nodeData);
    /**
     * removes selected nodes if exists
     * @param head
     * @param secondaryHead
     * @param nodeName
     * @return
     */
    secondaryNode* remove(primaryNode* head , secondaryNode* secondaryHead,string nodeName);
};


#endif //FOURTHASSIGNMENT_MODEL1_H
