#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};


class BST{
    private:
       Node *root;

    public:
       BST(){ root=nullptr; }   
       void preorder(Node *temp);
       void inorder(Node *temp);
       void postorder(Node *temp);
};


void BST::preorder(Node *temp){
    if (!temp)
        return;

    cout<<temp->data;
    preorder(temp->left);
    preorder(temp->right);
}


void BST::inorder(Node *temp){
    if (!temp)
        return;

    inorder(temp->left);
    cout<<temp->data;
    inorder(temp->right);
}


void BST::postorder(Node *temp){
    if (!temp)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data;
}


int main(){
    return 0;
}