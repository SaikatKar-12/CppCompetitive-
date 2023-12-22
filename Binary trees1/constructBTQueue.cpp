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
Node* construct(int arr[],int n){
    queue<Node*> q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        Node* temp=q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l) q.push(l);
        if(r) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
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
void bottomBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) cout<<root->data<<" ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}
void leftBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->data<<" ";
    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);
}
void rightBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    leftBoundary(root->right);
    if(root->right==NULL) leftBoundary(root->left);
    cout<<root->data<<" ";
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,8,INT_MIN,INT_MIN,9,INT_MIN,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=construct(arr,n);
    levelOrderQueue(root);
    cout<<endl;
    leftBoundary(root);
    bottomBoundary(root);
    rightBoundary(root->right);
    return 0;
}