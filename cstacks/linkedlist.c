#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* start=NULL;
struct Node* create_ll(struct Node* start){
    struct Node* new_node,*ptr;
    int val;
    printf("Enter -1 to end\n");
    printf("Enter your data:");
    scanf("%d",&val);
    while(val!=-1){
        new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->data=val;
        new_node->next=NULL;
        if(start==NULL){
            start=new_node;
        }else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }
        printf("Enter your data:");
        scanf("%d",&val); 
    }
    return start;
}
struct Node* display(struct Node* start){
    struct Node *ptr;
    ptr=start;
    while(ptr){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return start;
}
struct Node* Insert_beg(struct Node* start){
    struct Node* new_node;
    int val;
    printf("Enter -1 to end\n");
    printf("Enter your data:");
    scanf("%d",&val);
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=val;
    if(start==NULL){
            new_node->next=NULL;
            start=new_node;
    }else{
        new_node->next=start;
        start=new_node;
    }
    return start;
}
struct Node* Insert_end(struct Node* start){
    struct Node* new_node,*ptr;
    int val;
    printf("Enter -1 to end\n");
    printf("Enter your data:");
    scanf("%d",&val);
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=NULL;
    if(start==NULL){
            start=new_node;
    }else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
    }
    return start;
}
struct Node* Insert_mid(struct Node* start){
    if(start==NULL||start->next==NULL){
        return Insert_end(start);
    }
    struct Node* slow,*fast;
    slow=start;
    fast=start;
    while(fast->next->next && fast->next->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct Node* new_node,*ptr;
    int val;
    printf("Enter -1 to end\n");
    printf("Enter your data:");
    scanf("%d",&val);
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=slow->next;
    slow->next=new_node;
    return start;
}
struct Node* Insert_at(struct Node* start){
    int idx;
    printf("Enter your index:");
    scanf("%d",&idx);
    if(idx==0) return Insert_beg(start);
    struct Node* new_node,*ptr;
    int val;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    ptr=start;
    for(int i=1;i<idx;i++){
        if(ptr==NULL && i<idx){
            printf("Invalid idx\n");
            return start;
        }else if(ptr==NULL){
            return Insert_end(start);
        }
        ptr=ptr->next;
    }
    printf("Enter your data:");
    scanf("%d",&val);
    new_node->data=val;
    new_node->next=ptr->next;
    ptr->next=new_node;
    return start;
}
struct Node* delete_beg(struct Node* start){
    struct Node* ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct Node* delete_end(struct Node* start){
    struct Node* ptr,*temp;
    ptr=start;
    while(ptr->next->next){
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return start;
}
struct Node* delete_mid(struct Node* start){
    struct Node* slow,*fast;
    slow=start;
    fast=start;
    while(fast->next->next && fast->next->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
    return start;
}
struct Node* delete_at(struct Node* start){
    int idx;
    printf("Enter your index:");
    scanf("%d",&idx);
    if(idx==0) return delete_beg(start);
    struct Node *ptr;
    ptr=start;
    for(int i=1;i<idx;i++){
        if(ptr==NULL || ptr->next==NULL){
            printf("Invalid idx\n");
            return start;
        }
        ptr=ptr->next;
    }
    if(ptr==NULL || ptr->next==NULL){
            printf("Invalid idx\n");
            return start;
        }
    ptr->next=ptr->next->next;
    return start;
}
int main(){
    start=create_ll(start);
    start=display(start);
    // start=Insert_beg(start);
    // start=display(start);
    // start=Insert_end(start);
    // start=display(start);
    // start=Insert_mid(start);
    // start=display(start);
    // start=Insert_at(start);
    // start=display(start);
    // start=delete_beg(start);
    // start=display(start);
    // start=delete_end(start);
    // start=display(start);
    // start=delete_mid(start);
    // start=display(start);
    start=delete_at(start);
    start=display(start);
}