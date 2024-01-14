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
struct TreeNode* insertEle_rec(struct TreeNode* root,int data){
    if(root==NULL){
        struct TreeNode *ptr;
        ptr=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        ptr->val=data;
        ptr->left=NULL;
        ptr->right=NULL;
        root=ptr;
        return root;
    }
    if(root->val>data){
        root->left=insertEle_rec(root->left,data);
    }else{
        root->right=insertEle_rec(root->right,data);
    }
    return root;
}
void inorder(struct TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
void preorder(struct TreeNode* root){
    if(root==NULL) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct TreeNode* root){
    if(root==NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}
void printLevelOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Create a queue for level order traversal
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue a node from the queue
        struct TreeNode* current = queue[front++];
        printf("%d ", current->val);

        // Enqueue the left child
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        // Enqueue the right child
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    // Free the memory allocated for the queue
    free(queue);
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
void levelOrder(struct TreeNode* root){
    if(root==NULL) return;
    struct TreeNode** q=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*100);
    int f=0;
    int r=0;
    q[r++]=root;
    while(f<r){
        struct TreeNode* curr=q[f++];
        printf("%d ",curr->val);
        if(curr->left!=NULL){
            q[r++]=curr->left;
        }
        if(curr->right!=NULL){
            q[r++]=curr->right;
        }
    }
    free(q);
}
struct TreeNode* iop(struct TreeNode* root){
    struct TreeNode* pred=root->left;
    while(pred->right!=NULL){
        pred=pred->right;
    }
    return pred;
}
struct TreeNode* reverse(struct TreeNode* root){
    if(root==NULL) return NULL;
    struct TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    reverse(root->left);
    reverse(root->right);
    return root;
}
struct TreeNode* deleteNode(struct TreeNode* root,int key){
    if(root==NULL) return NULL;
    if(root->val==key){
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
        }
        if(root->left!=NULL && root->right!=NULL){
            struct TreeNode* pred=iop(root);
            root->val=pred->val;
            root->left=deleteNode(root->left,pred->val);
            return root;
        }
    }
    if(root->val>key){
        root->left=deleteNode(root->left,key);
    }else{
        root->right=deleteNode(root->right,key);
    }
    return root;
}
void preorder_itr(struct TreeNode* root){
    if(root==NULL) return;
    struct TreeNode** st=(struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int top=-1;
    top++;
    st[top]=root;
    while(top>=0){
        struct TreeNode* curr=st[top--];
        printf("%d ",curr->val);
        if(curr->right!=NULL){
            top++;
            st[top]=curr->right;
        }
        if(curr->left!=NULL){
            top++;
            st[top]=curr->left;
        }
    }
}
void postorder_itr(struct TreeNode* root){
    if(root==NULL) return;
    struct TreeNode** st=(struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int helper[50];
    int toph=-1;
    int top=-1;
    top++;
    st[top]=root;
    while(top>=0){
        struct TreeNode* curr=st[top--];
        toph++;
        helper[toph]=curr->val;
        if(curr->left!=NULL){
            top++;
            st[top]=curr->left;
        }
        if(curr->right!=NULL){
            top++;
            st[top]=curr->right;
        }
    }
    while(toph>=0){
        printf("%d ",helper[toph]);
        toph--;
    }
}
void inorder_itr(struct TreeNode* root){
    struct TreeNode** st=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*100);
    struct TreeNode* node=root;
    int top=-1;
    while(top>=0 || node!=NULL){
        if(node!=NULL){
            top++;
            st[top]=node;
            node=node->left;
        }else{
            struct TreeNode* temp =st[top];
            top--;
            printf("%d ",temp->val);
            node=temp->right;
        }
    }
}
int main(){
    root=insertEle_rec(root,8);
    root=insertEle_rec(root,2);
    root=insertEle_rec(root,7);
    root=insertEle_rec(root,6);
    root=insertEle_rec(root,3);
    root=insertEle_rec(root,1);
    root=insertEle_rec(root,5);
    root=insertEle_rec(root,10);
    root=insertEle_rec(root,9);
    inorder(root);
    printf("\n");
    inorder_itr(root);
    return 0;
}