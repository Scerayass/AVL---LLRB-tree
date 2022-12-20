#include "Model2.h"

secondaryNode *Model2::insert(primaryNode *head, secondaryNode * secondaryHead ,  string nodeName, int nodeData) {
    if(secondaryHead == NULL){
        secondaryNode* newNode = new secondaryNode(nodeName,nodeData);
        return newNode;
    }else if(secondaryHead->name == nodeName){

        return secondaryHead;
    }

    const char* nameString = nodeName.c_str();
    const char* nodeString = secondaryHead->name.c_str();

    if(lexicographical_compare(nodeString,nodeString+100,nameString,nameString+100)){
        secondaryHead->right = insert(head,secondaryHead->right , nodeName, nodeData);
    }else{
        secondaryHead->left =  insert(head,secondaryHead->left , nodeName, nodeData);
    }

    if( ( secondaryHead->right != NULL && secondaryHead->right->color ) && !( secondaryHead->left != NULL && secondaryHead->left->color) ){

        secondaryHead = rotateLeft(secondaryHead);
        changeColors(secondaryHead,secondaryHead->left);
    }
    if( (secondaryHead->left != NULL && secondaryHead->left->color) && (secondaryHead->left->left != NULL && secondaryHead->left->left->color) ){
        secondaryHead = rotateRight(secondaryHead);
        changeColors(secondaryHead,secondaryHead->right);
    }
    if( (secondaryHead->left != NULL && secondaryHead->left->color) && (secondaryHead->right != NULL && secondaryHead->right->color) ){
        secondaryHead->color = true;
        secondaryHead->left->color = false;
        secondaryHead->right->color = false;
    }

    return secondaryHead;
}

secondaryNode *Model2::rotateLeft(secondaryNode *node) {
    secondaryNode* tempRight = node->right;
    secondaryNode* tempRightLeft = tempRight->left;
    tempRight->left = node;
    node->right = tempRightLeft;
    return tempRight;
}

secondaryNode *Model2::rotateRight(secondaryNode *node) {
    secondaryNode* tempLeft = node->left;
    secondaryNode* tempLeftRight = tempLeft->right;
    tempLeft->right = node;
    node->left = tempLeftRight;
    return tempLeft;
}

void Model2::changeColors(secondaryNode *firstNode, secondaryNode *secondNode) {

    bool tempColor = firstNode->color;
    firstNode->color = secondNode->color;
    secondNode->color = tempColor;

}


