#include <iostream>
#include "Model2.h"
using namespace std;
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

    }
    if( (secondaryHead->left != NULL && secondaryHead->left->color) && (secondaryHead->left->left != NULL && secondaryHead->left->left->color) ){
        secondaryHead = rotateRight(secondaryHead);

    }
    if( (secondaryHead->left != NULL && secondaryHead->left->color) && (secondaryHead->right != NULL && secondaryHead->right->color) ){
        secondaryHead->color = true;
        secondaryHead->left->color = false;
        secondaryHead->right->color = false;
    }

    return secondaryHead;
}

secondaryNode *Model2::rotateLeft(secondaryNode *node) {
    secondaryNode *temp=node->right;
    node->right=temp->left;
    temp->left=node;
    temp->color=node->color;
    node->color= true;
    return temp;

}

secondaryNode *Model2::rotateRight(secondaryNode *node) {
    secondaryNode *temp=node->left;
    node->left=temp->right;
    temp->right=node;
    temp->color=node->color;
    node->color= true;
    return temp;

}

void Model2::changeColors(secondaryNode *firstNode, secondaryNode *secondNode) {

    bool tempColor = firstNode->color;
    firstNode->color = secondNode->color;
    secondNode->color = tempColor;

}

secondaryNode *Model2::findMin(secondaryNode *head) {
    if(head == NULL){
        return head;
    }
    else if(head->left== NULL){
        return head;
    }
    return findMin(head->left);

}

secondaryNode *Model2::deleteMin(secondaryNode *head) {
    if(head->left == NULL ){
        return NULL;
    }
    if( !(head->left != NULL && head->left->color) && !(head->left->left != NULL && head->left->left->color)){
        head = moveRedLeft(head);
    }

    return head;

}

secondaryNode *Model2::remove(primaryNode *head, secondaryNode *secondaryHead, string nodeName , string anotherNodeName) {
    // NULL SAFETY !!!!
    if(secondaryHead == NULL){
        cout << "yayaya";
    }
    cout << secondaryHead->name << endl;

    const char* nameString = nodeName.c_str();
    const char* nodeString = secondaryHead->name.c_str();
    cout << "merhaba" << endl;
    if(lexicographical_compare(nameString,nameString+100,nodeString,nodeString+100) && secondaryHead->name != nodeName){
        cout << nodeName << " - " << nodeString << endl;

        if(!isRed(secondaryHead->left) && !isRed(secondaryHead->left->left)){
            secondaryHead = moveRedLeft(secondaryHead);
        }
        secondaryHead->left = remove(head,secondaryHead->left,nodeName , anotherNodeName);

    }
    else{

        if(isRed(secondaryHead->left)){
            secondaryHead = rotateRight(secondaryHead);
        }
        if(secondaryHead->name == nodeName && secondaryHead->right == NULL){
            return NULL;
        }
        if(!isRed(secondaryHead->right) && !isRed(secondaryHead->right->left)){
            secondaryHead = moveRedLeft(secondaryHead);
        }
        if(secondaryHead->name == nodeName){
            secondaryNode * temp = findMin(secondaryHead->right);
            secondaryHead->name = temp->name;
            secondaryHead->data = temp->data;
            secondaryHead->right = deleteMin(secondaryHead->right);
        }else{
            secondaryHead->right = remove(head,secondaryHead->right,nodeName , anotherNodeName);

        }
        /*
        if(secondaryHead->left != NULL && secondaryHead->left->color ){
            secondaryHead = rotateRight(secondaryHead);
        }
        if(secondaryHead->name == nodeName && secondaryHead->right == NULL){
            //cout << "bruasi 2"<< endl;
            return NULL;
        }

        if( !(secondaryHead->right != NULL && secondaryHead->right->color) && !(secondaryHead->right->left != NULL && secondaryHead->right->left->color) ){

            secondaryHead = moveRedLeft(secondaryHead);
        }
        if ( secondaryHead->name == nodeName ){
            secondaryNode * temp = findMin(secondaryHead->right);
            secondaryHead->name = temp->name;
            secondaryHead->data = temp->data;
            secondaryHead->right = deleteMin(secondaryHead->right);
        }else{

            secondaryHead->right = remove(head,secondaryHead->right,nodeName , anotherNodeName);
        }*/
    }

    if( ( secondaryHead->right != NULL && secondaryHead->right->color ) && !( secondaryHead->left != NULL && secondaryHead->left->color) ){

        secondaryHead = rotateLeft(secondaryHead);

    }
    if( (secondaryHead->left != NULL && secondaryHead->left->color) && (secondaryHead->left->left != NULL && secondaryHead->left->left->color) ){
        secondaryHead = rotateRight(secondaryHead);

    }
    if( (secondaryHead->left != NULL && secondaryHead->left->color) && (secondaryHead->right != NULL && secondaryHead->right->color) ){

        secondaryHead->color = true;
        secondaryHead->left->color = false;
        secondaryHead->right->color = false;
    }
    return secondaryHead;

}

secondaryNode *Model2::moveRedRight(secondaryNode *head) {
    head->right->color= false;
    head->left->color= false;
    head->color= true;


    if( !(head->left->left != NULL && head->left->left->color) ){
        head= rotateRight(head);
        head->right->color= false;
        head->left->color= false;
        head->color= true;


    }
    return head;

}

secondaryNode *Model2::moveRedLeft(secondaryNode *head) {

    head->right->color= false;
    head->left->color= false;
    head->color= true;

    if( head->right->left != NULL && head->right->left->color ){
        head->right = rotateRight(head->right);
        head = rotateLeft(head);
        head->right->color= false;
        head->left->color= false;
        head->color= true;

    }
    return head;

}

bool Model2::isRed(secondaryNode *head) {
    if(head == NULL){
        return false;
    }
    return head->color;
}
/*

SecondaryNode *RedBlackTree::deletion(SecondaryNode *head, std::string name) {
    if(name<root->name){
        if(!isRed(root->left)&&!isRed(root->left->left)){
            root= moveRedLeft(root);
        }
        root->left= deletion(root->left,name);
    }
    else{
        if(isRed(root->left)){
            root= rotateRight(root);
        }
        if(root->name==name &&root->right== nullptr){
            return nullptr;
        }
        if(!isRed(root->right)&&!isRed(root->right->left)){
            root= moveRedLeft(root);
        }
        if(root->name==name){
            SecondaryNode *min= findMin(root->right);
            root->name=min->name;
            root->data=min->data;
            root->right= deleteMin(root->right);
        }
        else{
            root->right= deletion(root->right,name);
        }

    }
    if(isRed(root->right)&& !isRed(root->left)) root= rotateLeft(root);
    if(isRed(root->left)&& isRed(root->left->left))root=rotateRight(root);
    if(isRed(root->right)&& isRed(root->left))  flipcolors(root);
      return root;
}*/