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
        findBST(head,vector.at(1),"r" , "insert");

        //cout << tempNode->model1Secondary->name << endl;
        //cout << vector.at(1)<< "--";

        tempNode->model1Secondary = model1->insert(tempNode,tempNode->model1Secondary ,vector.at(2),stoi(vector.at(3)) );
        tempNode->model2Secondary = model1->insert(tempNode,tempNode->model1Secondary ,vector.at(2),stoi(vector.at(3)) );
        tempNode->model2Secondary->color = false;
        //tempNode->model2Secondary = model2->insert(tempNode,tempNode->model2Secondary,vector.at(2),stoi(vector.at(3)));
        /*
        if(tempNode->model1Secondary != NULL && tempNode->model2Secondary != NULL){


            tempNode->model1Secondary = model1->insert(tempNode,tempNode->model1Secondary ,vector.at(2),stoi(vector.at(3)) );

            tempNode->model2Secondary = model2->insert(tempNode,tempNode->model2Secondary,vector.at(2),stoi(vector.at(3)));
        }else{
            secondaryNode* newSecondary1 = new secondaryNode(vector.at(2),stoi(vector.at(3)));
            secondaryNode* newSecondary2 = new secondaryNode(vector.at(2),stoi(vector.at(3)));

            newSecondary1->height = 1;
            newSecondary2->height = 1;

            tempNode->model1Secondary = newSecondary1;
            tempNode->model2Secondary = newSecondary2;
        }*/
        tempNode = NULL;
    }

}

void ModelCommon::printAllItems(primaryNode *head) {
    if ( !head ){
        return;
    }

    cout << head->name << endl;
    printAllItems(head->left);



    printAllItems(head->right);


}
void ModelCommon::printSecondaries(secondaryNode* head){
    if(!head){
        return;
    }
    cout << head->name << " ";
    printSecondaries(head->left);
    printSecondaries(head->right);

}


primaryNode * ModelCommon::remove(vector<string> vector) {

}

primaryNode *ModelCommon::findBST(primaryNode *head,string name,string location,string type) {

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
        head->right = findBST(head->right,name,"r" , "insert");
    }else{
        head->left =  findBST(head->left,name,"l" , "insert");
    }
    return head;
}