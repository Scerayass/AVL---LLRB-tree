#include "ModelCommon.h"
#include <vector>
#include <iostream>
#include <queue>
#include "Nodes.h"

using namespace std;

primaryNode* tempNode;
secondaryNode* tempSecondaryNode;
void ModelCommon::insert(vector<string> vector) {

    if(head == NULL){

        head = new primaryNode(vector.at(1));
        secondaryNode* secondItem1 = new secondaryNode(vector.at(2),stoi(vector.at(3)));
        secondaryNode* secondItem2 = new secondaryNode(vector.at(2),stoi(vector.at(3)));

        head->height = 1;
        head->model1Secondary = secondItem1;
        head->model2Secondary = secondItem2;

        model1->head = head;
        model2->head = head;
    }else{
        findBST(head,vector.at(1));

        tempNode->model1Secondary = model1->insert(tempNode,tempNode->model1Secondary ,vector.at(2),stoi(vector.at(3)) );
        tempNode->model2Secondary = model2->insert(tempNode,tempNode->model2Secondary ,vector.at(2),stoi(vector.at(3)) );
        tempNode->model2Secondary->color = false;

        tempNode = NULL;
    }

}


void ModelCommon::remove(vector<string> vector) {
    findBST(head,vector.at(1));
    // sending to AVL and LLRBL tree
    tempNode->model1Secondary = model1->remove(tempNode,tempNode->model1Secondary,vector.at(2));
    tempNode->model2Secondary = model2->remove(tempNode,tempNode->model2Secondary,vector.at(2)  ,"icecream");
    tempNode = NULL;
}

primaryNode *ModelCommon::findBST(primaryNode *head,string name) {

    if (head == NULL){
        primaryNode* newNode = new primaryNode(name);
        newNode->model1Secondary = NULL;
        newNode->model2Secondary = NULL;

        tempNode = newNode;
        return newNode;
    }else if(head->name == name){

        tempNode = head;
        return head;
    }
    const char* nodeString = head->name.c_str();
    const char* nameString = name.c_str();

    if(lexicographical_compare(nodeString,nodeString+100,nameString,nameString+100)){
        head->right = findBST(head->right,name);
    }else{
        head->left =  findBST(head->left,name);
    }
    return head;
}

secondaryNode* ModelCommon::findSecondary(secondaryNode* head,string name){
    if(head == NULL){
        tempSecondaryNode = NULL;
        return NULL;
    }else if(head->name == name){
        tempSecondaryNode = head;
        return head;
    }
    const char* nodeString = head->name.c_str();
    const char* nameString = name.c_str();

    if(lexicographical_compare(nodeString,nodeString+100,nameString,nameString+100)){
        head->right = findSecondary(head->right,name);
    }else{
        head->left =  findSecondary(head->left,name);
    }
    return head;

}

void ModelCommon::printAllItemsInCategory(primaryNode* head,string nodeString,ofstream &outputFile , int modelNumber) {
    findBST(head,nodeString);


    outputFile << "\""<<  nodeString << "\":";
    if(modelNumber == 1){
        printSecondaries(tempNode->model1Secondary,outputFile);
    }else if (modelNumber == 2){
        printSecondaries(tempNode->model2Secondary,outputFile);
    }

    tempNode = NULL;


}

void ModelCommon::updateData(primaryNode* head , string primaryString , string secondaryString , int updatedData) {
    findBST(head,primaryString);
    findSecondary(tempNode->model1Secondary,secondaryString);

    tempSecondaryNode->data = updatedData;

    tempNode = NULL;
    tempSecondaryNode = NULL;
}

void ModelCommon::printItem(primaryNode* head , string primaryString , string secondaryString,ofstream &outputFile , int modelNumber) {

    findBST(head,primaryString);
    if(modelNumber == 1){
        findSecondary(tempNode->model1Secondary,secondaryString);
    }else if(modelNumber == 2){
        findSecondary(tempNode->model2Secondary,secondaryString);
    }


    if(tempSecondaryNode == NULL){
        return;
    }else{
        outputFile << "\n\"" << primaryString << "\":\n\t\"" << secondaryString << "\":\"" << tempSecondaryNode->data << "\"\n";
    }
    tempNode = NULL;
    tempSecondaryNode = NULL;
}

void ModelCommon::find(primaryNode* head , string primaryString , string secondaryString,ofstream &outputFile) {
    // it is same with printItem that's why im using printItem
}
void ModelCommon::printAllItems(primaryNode *head ,ofstream &outputFile , int modelNumber) {

    if (!head){

        outputFile << endl;
        return ;
    }
    queue<primaryNode*> primaryQueue;
    primaryQueue.push(head);
    while(primaryQueue.empty() == false){
        int count = primaryQueue.size();
        //cout << count << endl;
        while( count > 0 ){
            primaryNode* temp = primaryQueue.front();
            //cout << temp->name << " ";
            primaryQueue.pop();
            outputFile << "\""<<  temp->name << "\":";
            if(modelNumber == 1){
                printSecondaries(temp->model1Secondary,outputFile);
            }else if (modelNumber == 2){
                printSecondaries(temp->model2Secondary,outputFile);
            }

            if(temp->left != NULL){

                primaryQueue.push(temp->left);
            }
            if(temp->right != NULL){

                primaryQueue.push(temp->right);
            }
            count--;
        }
        //cout << endl;
    }
}

void ModelCommon::printSecondaries(secondaryNode *node ,ofstream &outputFile) {

    if (!node){
        outputFile << "{}\n";
        return ;
    }
    //outputFile << "\n\t";
    queue<secondaryNode*> secondaryQueue;
    secondaryQueue.push(node);
    while(secondaryQueue.empty() == false){
        int count = secondaryQueue.size();
        outputFile << "\n\t";
        while( count > 0 ){
            secondaryNode* temp = secondaryQueue.front();
            //cout << temp->name << " ";
            //cout  << count << "  aspodjapoajs";
            secondaryQueue.pop();
            outputFile << "\""<<  temp->name << "\":\"" << temp->data << "\"";
            if(count > 1){
                outputFile << ",";
            }
            if(temp->left != NULL){

                secondaryQueue.push(temp->left);
            }
            if(temp->right != NULL){

                secondaryQueue.push(temp->right);
            }
            count--;
        }
        //outputFile << "\n\t";
        //cout << endl;
    }
    outputFile << "\n";


}