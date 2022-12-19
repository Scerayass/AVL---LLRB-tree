#include "ModelCommon.h"
#include <vector>
#include <iostream>
#include "Nodes.h"

using namespace std;


void ModelCommon::insert(vector<string> vector) {

    if(head == NULL){

        head = new primaryNode();
        secondaryNode* secondItem = new secondaryNode();
        cout << vector.at(1) << endl;
        head->name = vector.at(1);
        head->left = NULL;
        head->right =  NULL;
        head->height = 1;
        head->model1Secondary = secondItem;
        head->model2Secondary = secondItem;

        secondItem->height = 1;
        secondItem->left = NULL;
        secondItem->right = NULL;
        secondItem->name = vector.at(2);
        secondItem->data = stoi(vector.at(3));
        secondItem->color = true;

        model1->head = head;
        model2->head = head;
    }else{

        primaryNode* temp = findBST(head,vector.at(1),"r" , "insert");
        cout << temp->name << endl;
        if(temp->model1Secondary != NULL && temp->model2Secondary != NULL){
            model1->insert(temp,temp->model1Secondary);
            model2->insert(temp,temp->model2Secondary);
        }else{
            secondaryNode* newSecondary = new secondaryNode();
            newSecondary->name = vector.at(2);
            newSecondary->data = stoi(vector.at(3));
            newSecondary->left = NULL;
            newSecondary->right = NULL;
            newSecondary->color = true;

            temp->model1Secondary = newSecondary;
            temp->model2Secondary = newSecondary;
        }
    }



}

void ModelCommon::printAllItems(primaryNode *head) {
    if ( !head ){
        return;
    }
    printAllItems(head->left);
    cout << head->name << endl;
    printAllItems(head->right);
}

primaryNode * ModelCommon::remove(vector<string> vector) {

}

primaryNode *ModelCommon::findBST(primaryNode *head,string name,string location,string type) {

    if (head == NULL){
        primaryNode* newNode = new primaryNode();
        newNode->name = name;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }else if(head->name == name){
        cout << "gelmiyon mu bura";
        return head;
    }

    const char* nodeString = head->name.c_str();
    const char* nameString = name.c_str();

    if(lexicographical_compare(nodeString,nodeString+100,nameString,nameString+100)){
        head->right = findBST(head->right,name,"r" , "insert");
    }else{
        head->left =  findBST(head->left,name,"l" , "insert");
    }
    return head;
}