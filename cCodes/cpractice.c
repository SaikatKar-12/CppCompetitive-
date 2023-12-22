#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* start =NULL;
struct Node* create_ll(struct Node* start){
    struct Node *new_node,*ptr;
    int val;
    printf("Enter -1 to end\n");
    printf("Enter your data: ");
    scanf("%d",&val);
    while(val!=-1){
        new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data=val;
        if(start==NULL){
            new_node->next=NULL;
            start=new_node;
        }else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
                ptr->next=new_node;
                new_node->next=NULL;
        }
        printf("Enter your data: ");
        scanf("%d",&val);
    }
    return start;
}
struct Node* display(struct Node *start){
    struct Node* ptr;
    if(start==NULL){
        printf("list empty");
        return start;
    }
    ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return start;
}
struct Node* insertAtbeg(struct Node *start){
    int val;
    printf("Enter -1 to end\n");
    printf("Enter your data: ");
    scanf("%d",&val);
    struct Node *new_node;
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=start;
    start=new_node;
    return start;
}
struct Node* deleteAt(int idx,struct Node *start){
    struct Node* temp=start;
    for(int i=0;i<idx;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return start;
}
int main(){
    int opt;
    int idx;
    printf("*****Main Menu******\n");
    printf("1.create linked list\n");
    printf("2.display\n");
    printf("3.insert at beginning\n");
    printf("4.Delete node\n");
    printf("5.exit\n");

    while(opt!=4){
    printf("Enter your option: ");
    scanf("%d",&opt);
        switch(opt){
            case 1:
                start=create_ll(start);
                break;
            case 2:
                start=display(start);
                break;
            case 3:
                start=insertAtbeg(start);
                break;
            case 4:
                printf("Enter a index: ");
                scanf("%d",&idx);
                start=deleteAt(idx,start);
                break;
            case 5:
                break;
        }
    }
    
    return 0;
}