#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode *root=NULL;
struct TreeNode *insertEle_itr(struct TreeNode* root,int data){
    struct TreeNode *ptr,*nodeptr,*parentptr;
    ptr=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    ptr->val=data;
    ptr->left=NULL;
    ptr->right=NULL;
    if(root==NULL){
        root=ptr;
    }else{
        nodeptr=root;
        parentptr=NULL;
        while(nodeptr!=NULL){
            parentptr=nodeptr;
            if(nodeptr->val>data){
                nodeptr=nodeptr->left;
            }else{
                nodeptr=nodeptr->right;
            }
        }
        if(parentptr->val>data){
            parentptr->left=ptr;
        }else{
            parentptr->right=ptr;
        }
    }
    return root;
}

void inorder(struct TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

// Function to free the memory allocated for the binary tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    root=insertEle_itr(root,8);
    root=insertEle_itr(root,2);
    root=insertEle_itr(root,7);
    root=insertEle_itr(root,6);
    root=insertEle_itr(root,3);
    root=insertEle_itr(root,1);
    root=insertEle_itr(root,5);
    root=insertEle_itr(root,10);
    root=insertEle_itr(root,9);
    inorder(root);
    printf("\n");
    
    return 0;
}