#include <iostream>
#include "Model1.h"

secondaryNode* Model1::insert(primaryNode *head, secondaryNode * secondaryHead ,  string nodeName, int nodeData) {

    if(secondaryHead == NULL){

        secondaryNode* newNode = new secondaryNode(nodeName,nodeData);
        newNode->height = 1;

        return newNode;
    }else if(secondaryHead->name == nodeName){
        return secondaryHead;
    }

    const char* nodeString = secondaryHead->name.c_str();
    const char* nameString = nodeName.c_str();

    if(lexicographical_compare(nodeString,nodeString+100,nameString,nameString+100)){
        secondaryHead->right = insert(head,secondaryHead->right , nodeName, nodeData);
    }else{
        secondaryHead->left =  insert(head,secondaryHead->left , nodeName, nodeData);
    }
    secondaryHead->height = 1 + maxHeight(secondaryHead->left,secondaryHead->right);

    int balanceValue = isBalanced(secondaryHead);

    const char* leftNodeString;
    const char* rightNodeString;
    if(secondaryHead->left != NULL){
        leftNodeString = secondaryHead->left->name.c_str();
    }
    if(secondaryHead->right != NULL){
        rightNodeString = secondaryHead->right->name.c_str();
    }

    if(balanceValue > 1 && lexicographical_compare(nameString,nameString+100,leftNodeString,leftNodeString+100)){
        return rotateRight(secondaryHead);
    }
    if(balanceValue < -1 && lexicographical_compare(rightNodeString,rightNodeString+100,nameString,nameString+100)){
        return rotateLeft(secondaryHead);
    }

    if(balanceValue > 1 && lexicographical_compare(leftNodeString,leftNodeString+100,nameString,nameString+100)){

        secondaryHead->left = rotateLeft(secondaryHead->left);
        return rotateRight(secondaryHead);
    }

    if(balanceValue < -1 && lexicographical_compare(nameString,nameString+100,rightNodeString,rightNodeString+100)){

        secondaryHead->right = rotateRight(secondaryHead->right);
        return rotateLeft(secondaryHead);
    }


    return secondaryHead;
}

int Model1::maxHeight(secondaryNode *node1 , secondaryNode* node2){
    if (node1 == NULL && node2 == NULL){
        return 0;
    }else if ( node1 != NULL){
        return node1->height;
    }else if (node2 != NULL){
        return node2->height;
    }
}


int Model1::isBalanced(secondaryNode* node){
    int nodeLeftHeight;
    int nodeRightHeight;

    if(node->left == NULL){
        nodeLeftHeight = 0;
    }else{
        nodeLeftHeight = node->left->height;
    }

    if(node->right == NULL){
        nodeRightHeight = 0;
    }else{
        nodeRightHeight = node->right->height;
    }

    return nodeLeftHeight - nodeRightHeight;
}

secondaryNode* Model1::rotateRight(secondaryNode* node){

    secondaryNode* tempLeft = node->left;
    secondaryNode* tempLeftRight = tempLeft->right;
    tempLeft->right = node;
    node->left = tempLeftRight;

    node->height = 1 + maxHeight(node->left,node->right);
    tempLeft->height = 1 + maxHeight(tempLeft->left,tempLeft->right);
    return tempLeft;
}

secondaryNode* Model1::rotateLeft(secondaryNode* node){
    secondaryNode* tempRight = node->right;
    secondaryNode* tempRightLeft = tempRight->left;
    tempRight->left = node;
    node->right = tempRightLeft;

    node->height = 1 + maxHeight(node->left,node->right);
    tempRight->height = 1 + maxHeight(tempRight->left,tempRight->right);
    return tempRight;

}

secondaryNode *Model1::remove(primaryNode *head, secondaryNode *secondaryHead, string nodeName) {

    if(secondaryHead == NULL){
        return NULL;
    }
    const char* nodeString = secondaryHead->name.c_str();
    const char* nameString = nodeName.c_str();


    if (secondaryHead->name == nodeName ){

        if(secondaryHead->left != NULL && secondaryHead->right != NULL){
            secondaryNode* currNode = secondaryHead;
            while(currNode->left != NULL){
                currNode = currNode->left;
            }
            secondaryHead->name = currNode->name;
            secondaryHead->right = remove(head,secondaryHead->right,currNode->name);
        }else{
            secondaryNode* tempNode;

            if(secondaryHead->left == NULL && secondaryHead->right == NULL){
                tempNode = secondaryHead;
                secondaryHead = NULL;
            }else if (secondaryHead->left != NULL){
                tempNode = secondaryHead->left;
                *secondaryHead = *tempNode;
                free(tempNode);
            }else{
                tempNode = secondaryHead->right;
                *secondaryHead = *tempNode;
                free(tempNode);
            }

        }
    }
    else if(lexicographical_compare(nodeString,nodeString+100,nameString,nameString+100)){

        secondaryHead->right = remove(head,secondaryHead->right,nodeName);
    }else if (lexicographical_compare(nameString,nameString+100,nodeString,nodeString+100)){

        secondaryHead->left = remove(head,secondaryHead->left,nodeName);
    }
    if(secondaryHead == NULL){
        return NULL;
    }
    secondaryHead->height = 1 + maxHeight(secondaryHead->left,secondaryHead->right);
    int balanceValue = isBalanced(secondaryHead);

    const char* leftNodeString;
    const char* rightNodeString;
    if(secondaryHead->left != NULL){
        leftNodeString = secondaryHead->left->name.c_str();
    }
    if(secondaryHead->right != NULL){
        rightNodeString = secondaryHead->right->name.c_str();
    }
    if(balanceValue > 1 && lexicographical_compare(nameString,nameString+100,leftNodeString,leftNodeString+100)){

        return rotateRight(secondaryHead);
    }
    if(balanceValue < -1 && lexicographical_compare(rightNodeString,rightNodeString+100,nameString,nameString+100)){

        return rotateLeft(secondaryHead);
    }

    if(balanceValue > 1 && lexicographical_compare(leftNodeString,leftNodeString+100,nameString,nameString+100)){

        secondaryHead->left = rotateLeft(secondaryHead->left);
        return rotateRight(secondaryHead);
    }

    if(balanceValue < -1 && lexicographical_compare(nameString,nameString+100,rightNodeString,rightNodeString+100)){

        secondaryHead->right = rotateRight(secondaryHead->right);
        return rotateLeft(secondaryHead);
    }


    return secondaryHead;
}