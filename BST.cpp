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
    public:
       Node *root;
       BST(){ root=nullptr; }   
       Node *create(Node *temp, int data);
       void preorder(Node *temp);
       void inorder(Node *temp);
       void postorder(Node *temp);
       void levelorder();
       void traversals();
       bool search(Node *temp, int data);
       Node *deletenode(Node *temp, int data);
};


Node* BST::create(Node *temp, int data){
    if (!temp){
        temp=new Node(data);
        return temp;
    }
    
    if (temp->data==data)
        return temp;
    
    if (data < temp->data)    
        temp->left=create(temp->left,data);
    
    else if (data > temp->data)    
        temp->right=create(temp->right,data);
    
    return temp;    
}


bool BST::search(Node *temp, int data){
    if (!temp)
        return false; 

    if (temp->data == data)    
        return true;

    return search(temp->left,data) || search(temp->right,data);
}


Node* successor(Node *temp){
    while (temp->left)
        temp=temp->left;

    return temp;    
}


Node* BST::deletenode(Node *temp, int data){
    if (!temp){
        printf("\n%d does not exist in BST!!!",data);
        return temp;
    }

    if (data < temp->data)
        temp->left=deletenode(temp->left,data);

    else if (data > temp->data)   
        temp->right=deletenode(temp->right,data);

    else{
        Node *s;
        if (!temp->left){
            s=temp->right;
            delete temp;
            return s;
        }

        else if (!temp->right){
            s=temp->left;
            delete temp;
            return s;
        }

        s=successor(temp->right);
        temp->data=s->data;
        temp->right=deletenode(temp->right,s->data);     
    }    

    return temp;
}


void BST::preorder(Node *temp){
    if (!temp)
        return;

    cout<<temp->data<<"-->";
    preorder(temp->left);
    preorder(temp->right);
}


void BST::inorder(Node *temp){
    if (!temp)
        return;

    inorder(temp->left);
    cout<<temp->data<<"-->";
    inorder(temp->right);
}


void BST::postorder(Node *temp){
    if (!temp)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<"-->";
}


void BST::levelorder(){
    deque<Node*> q;
    Node *temp=root;
    q.push_back(temp);

    while (!q.empty()){
        temp=q.front();
        q.pop_front();
        cout<<temp->data<<"-->";

        if (temp->left)
           q.push_back(temp->left);
        if (temp->right)   
           q.push_back(temp->right);
    }
}


void BST::traversals(){
    cout<<endl<<endl<<"Preorder Traversal : " ; preorder(root);
    cout<<endl<<"Inorder Traversal : " ; inorder(root);
    cout<<endl<<"Postorder Traversal : " ; postorder(root);
    cout<<endl<<"Levelorder Traversal : " ; levelorder();
    cout<<endl;
}


int main(){
    BST bst;
    bst.root=bst.create(bst.root,40);
    bst.root=bst.create(bst.root,20);
    bst.root=bst.create(bst.root,10);
    bst.root=bst.create(bst.root,50);
    bst.root=bst.create(bst.root,60);
    bst.root=bst.create(bst.root,100);
    bst.root=bst.create(bst.root,15);
    bst.root=bst.create(bst.root,45);
    bst.root=bst.create(bst.root,45);
    bst.traversals();
    

    int n=12;
    if (bst.search(bst.root,n))
        printf("%d found!!!",n);
    else 
        printf("%d not found!!!",n);

    bst.root=bst.deletenode(bst.root,10);
    bst.root=bst.deletenode(bst.root,40);
    bst.root=bst.deletenode(bst.root,44);

    bst.traversals();

    return 0;
}
