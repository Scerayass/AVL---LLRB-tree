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
        tempNode->model2Secondary = model1->insert(tempNode,tempNode->model1Secondary ,vector.at(2),stoi(vector.at(3)) );
        tempNode->model2Secondary->color = false;

        tempNode = NULL;
    }

}

void ModelCommon::printAllItems222(primaryNode *head) {
    if ( !head ){
        return;
    }

    cout << head->name << " --- ";
    printSecondaries222(head->model1Secondary);
    cout << endl;
    printAllItems222(head->left);
    printAllItems222(head->right);
}
void ModelCommon::printSecondaries222(secondaryNode* head){
    if(!head){
        return;
    }
    cout << head->name << " , ";
    printSecondaries222(head->left);
    printSecondaries222(head->right);

}


void ModelCommon::remove(vector<string> vector) {
    findBST(head,vector.at(1));
    tempNode->model1Secondary = model1->remove(tempNode,tempNode->model1Secondary,vector.at(2));
    tempNode = NULL;
}

primaryNode *ModelCommon::findBST(primaryNode *head,string name) {

    if (head == NULL){
        primaryNode* newNode = new primaryNode(name);
        newNode->model1Secondary = NULL;

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

void ModelCommon::printAllItemsInCategory(primaryNode* head,string nodeString) {
    findBST(head,nodeString);


    outputFile << "\""<<  nodeString << "\":";
    printSecondaries(tempNode->model1Secondary);
    tempNode = NULL;


}

void ModelCommon::updateData(primaryNode* head , string primaryString , string secondaryString , int updatedData) {
    findBST(head,primaryString);
    findSecondary(tempNode->model1Secondary,secondaryString);

    tempSecondaryNode->data = updatedData;

    tempNode = NULL;
    tempSecondaryNode = NULL;
}

void ModelCommon::printItem(primaryNode* head , string primaryString , string secondaryString) {

    findBST(head,primaryString);
    findSecondary(tempNode->model1Secondary,secondaryString);

    if(tempSecondaryNode == NULL){
        return;
    }else{
        outputFile << "\n\"" << primaryString << "\":\n\t\"" << secondaryString << "\":\"" << tempSecondaryNode->data << "\"\n";
    }
    tempNode = NULL;
    tempSecondaryNode = NULL;
}

void ModelCommon::find(primaryNode* head , string primaryString , string secondaryString) {

}
void ModelCommon::printAllItems(primaryNode *head) {

    if (!head){

        outputFile << endl;
        return ;
    }
    queue<primaryNode*> primaryQueue;
    primaryQueue.push(head);
    while(primaryQueue.empty() == false){
        int count = primaryQueue.size();
        cout << count << endl;
        while( count > 0 ){
            primaryNode* temp = primaryQueue.front();
            cout << temp->name << " ";
            primaryQueue.pop();
            outputFile << "\""<<  temp->name << "\":";
            printSecondaries(temp->model1Secondary);
            if(temp->left != NULL){

                primaryQueue.push(temp->left);
            }
            if(temp->right != NULL){

                primaryQueue.push(temp->right);
            }
            count--;
        }
        cout << endl;
    }
}

void ModelCommon::printSecondaries(secondaryNode *node) {

    if (!node){
        outputFile << "{}\n";
        return ;
    }
    outputFile << "\n\t";
    queue<secondaryNode*> secondaryQueue;
    secondaryQueue.push(node);
    while(secondaryQueue.empty() == false){
        int count = secondaryQueue.size();

        while( count > 0 ){
            secondaryNode* temp = secondaryQueue.front();
            cout << temp->name << " ";
            cout  << count << "  aspodjapoajs";
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
        outputFile << "\n\t";
        cout << endl;
    }
    outputFile << "\n";


}