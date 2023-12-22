#include<stdio.h>
#include<malloc.h>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* root;
void create_tree(struct TreeNode *root){
    root=NULL;
}
struct TreeNode *insert_element(struct TreeNode* root,int data){
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
struct TreeNode* iop(struct TreeNode* root){
        struct TreeNode* pred= root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
}
struct TreeNode* delete_node(struct TreeNode* root,int key){
    if(root==NULL) return NULL;
    if(root->val==key){
        if(root->left==NULL && root->right==NULL) return NULL;
        else if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
                else return root->right;
        }else{
            struct TreeNode* pred=iop(root);
            root->val=pred->val;
            root->left=delete_node(root->left,pred->val);
        }
    }
    else if(root->val>key){
        root->left=delete_node(root->left,key);
    }
    else{
        root->right=delete_node(root->right,key);
    }
    return root;
}
int main(){
    create_tree(root);
    int data;
    printf("Enter -1 to end");
    printf("Enter element:");
    scanf("%d",&data);

    while(data!=-1){
    root=insert_element(root,data);
    printf("Enter -1 to end");
    printf("Enter element:");
    scanf("%d",&data);
    }
    inorder(root);
    printf("\n");
    root=delete_node(root,7);
    inorder(root);
    return 0;
}