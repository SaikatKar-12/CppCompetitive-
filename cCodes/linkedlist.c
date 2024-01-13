#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
struct Node *start=NULL;
struct Node * createll(struct Node* start){
    struct Node *ptr;
    int data;
    printf("Enter Your Data:");
    scanf("%d",&data);
    while(data!=-1){
        ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->val=data;
        ptr->next=NULL;
        if(start==NULL){
            start=ptr;
        }else{
            struct Node* temp;
            temp=start;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
        }
        printf("Enter Your Data:");
        scanf("%d",&data);
    }
    return start;
}
struct Node* display(struct Node* start){
    struct Node* temp;
    temp=start;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    return start;
}
struct Node* insertatBeg(struct Node* start){
    int n;
    printf("Enter data:");
    scanf("%d",&n);
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->val=n;
    ptr->next=start;
    start=ptr;
    return start;
}
struct Node* insertAtmid(struct Node* start){
    struct Node* slow;
    struct Node* fast;
    slow=start;
    fast=start;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    int n;
    printf("Enter data:");
    scanf("%d",&n);
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->val=n;
    ptr->next=slow->next;
    slow->next=ptr;
    return start;
}
struct Node* insertatidx(struct Node* start){
    int n;
    printf("Enter data:");
    scanf("%d",&n);
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->val=n;
    int idx;
    printf("Enter idx:");
    scanf("%d",&idx);
    struct Node* temp;
    temp=start;
    for(int i=0;i<idx-1;i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    return start;
    
}
int main(){
    start=createll(start);
    start=display(start);
    start=insertatidx(start);
    start=display(start);
    return 0;
}