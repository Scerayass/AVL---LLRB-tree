#ifndef FOURTHASSIGNMENT_MODELCOMMON_H
#define FOURTHASSIGNMENT_MODELCOMMON_H


#include "Model1.h"
#include "Model2.h"
#include <vector>
#include <fstream>
#include "Nodes.h"

class ModelCommon {
public:
    ofstream outputFile1;
    ofstream outputFile2;
    primaryNode* head;
    Model1* model1;
    Model2* model2;
    /**
     * insert a new node to tree
     * @param vector
     */
    void insert(vector<string> vector);
    /**
     * finds given node and returns it
     * @param head
     * @param name
     * @return
     */
    primaryNode* findBST(primaryNode* head,string name);
    /**
     * removes selected nodes if exists
     * @param vector
     */
    void remove(vector<string> vector);
    /**
     * prints all items at tree
     * @param head
     * @param outputFile
     * @param ModelNumber
     */
    void printAllItems(primaryNode* head , ofstream & outputFile ,int ModelNumber);

    /**
     * prints secondary nodes to outputFile
     * @param node
     * @param outputFile
     */
    void printSecondaries(secondaryNode* node,ofstream &outputFile);

    /**
     * prints selected category's nodes
     * @param head
     * @param nodeString
     * @param outputFile
     * @param modelNumber
     */
    void printAllItemsInCategory(primaryNode* head,string nodeString,ofstream &outputFile, int modelNumber);
    /**
     * prints selected Item
     * @param head
     * @param primaryString
     * @param secondaryString
     * @param outputFile
     * @param modelNumber
     */
    void printItem(primaryNode* head , string primaryString , string secondaryString,ofstream &outputFile , int modelNumber);
    /**
     * finds and prints selected Item
     * @param head
     * @param primaryString
     * @param secondaryString
     * @param outputFile
     */
    void find(primaryNode* head , string primaryString , string secondaryString,ofstream &outputFile);
    /**
     * updates selected Item
     * @param head
     * @param primaryString
     * @param secondaryString
     * @param updatedData
     */
    void updateData(primaryNode* head , string primaryString , string secondaryString , int updatedData);
    /**
     * finds secondary nodes
     * @param head
     * @param name
     * @return
     */
    secondaryNode* findSecondary(secondaryNode* head,string name);

};


#endif //FOURTHASSIGNMENT_MODELCOMMON_H
