#include "ModelCommon.h"
#include <vector>
#include <iostream>
#include "Nodes.h"

using namespace std;

primaryNode* tempNode;
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
    printSecondaries(head->model1Secondary);
    cout << endl;
    printAllItems(head->left);
    printAllItems(head->right);
}
void ModelCommon::printSecondaries222(secondaryNode* head){
    if(!head){
        return;
    }
    cout << head->name << " , ";
    printSecondaries(head->left);
    printSecondaries(head->right);

}


void ModelCommon::remove(vector<string> vector) {
    findBST(head,vector.at(1));
    tempNode->model1Secondary = model1->remove(tempNode,tempNode->model1Secondary,vector.at(2));
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

void ModelCommon::printAllItemsInCategory(primaryNode* head,string nodeString) {

}

void ModelCommon::updateData(primaryNode* head , string primaryString , string secondaryString , int updatedData) {


}

void ModelCommon::printItem(primaryNode* head , string primaryString , string secondaryString) {

}

void ModelCommon::find(primaryNode* head , string primaryString , string secondaryString) {

}
void ModelCommon::printAllItems(primaryNode *head) {

}
