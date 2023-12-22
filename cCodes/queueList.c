#include<stdio.h>
#include<malloc.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* f=NULL;
struct Node* r=NULL;
void enqueue(int val){
    if(f==NULL){
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->data=val;
        ptr->next=NULL;
        f=r=ptr;
        
    }else{
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->data=val;
        ptr->next=NULL;
        r->next = ptr;
        r=r->next;
    }
}
void dequeue(){
    if(f==NULL){
        printf("queue underflow\n");
    }else{
        f=f->next;
    }
}
void print(){
    if(f==NULL){
        printf("queue is empty\n");
    }else{
        struct Node* temp=f;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(8);
    print();
    dequeue();
    print();
    dequeue();
    enqueue(9);
    print();
    return 0;
}