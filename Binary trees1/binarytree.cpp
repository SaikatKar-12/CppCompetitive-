#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void display(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root){
    if(root==NULL) return 0;
    return root->data+sum(root->left)+sum(root->right);
}
int size(Node* root){
    if(root==NULL) return 0;
    int len=1+size(root->left)+size(root->right);
    return len;

}
int maxInTree(Node* root){
    if(root==NULL) return INT_MIN;
    int lmax=maxInTree(root->left);
    int rmax=maxInTree(root->right);
    return max(root->data,max(lmax,rmax));
}
int minInTree(Node* root){
    if(root==NULL) return INT_MAX;
    int lmax=minInTree(root->left);
    int rmax=minInTree(root->right);
    return min(root->data,min(lmax,rmax));
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
int prodTree(Node* root){
    if(root==NULL) return 1;
    return root->data*prodTree(root->left)*prodTree(root->right);
}
void levelOrderQueue(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(14);
    Node* e=new Node(5);
    Node* f=new Node(6);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    display(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<maxInTree(a);
    cout<<endl;
    cout<<level(a);
    cout<<endl;
    cout<<prodTree(a);
    cout<<endl;
    cout<<minInTree(a);
    cout<<endl;
    levelOrderQueue(a);
    return 0;
}