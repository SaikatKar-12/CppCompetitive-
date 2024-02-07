#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* next;
};
struct queue{
    struct Node* front;
    struct Node* rear;
};
struct queue* create_q(){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
void enqueue(struct queue* q,int val){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=NULL;
    if(q->front==NULL){
        q->front=ptr;
        q->rear=ptr;
    }else{
        q->rear->next=ptr;
        q->rear=ptr;
    }
}
int dequeue(struct queue* q){
    int temp;
    if(q->front==NULL){
        printf("queue empty\n");
        return -1;
    }else{
        temp=q->front->data;
        q->front=q->front->next;
    }
    return temp;
}
void display(struct queue* q){
    struct Node* temp=q->front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    struct queue* q=create_q();
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    display(q);
    dequeue(q);
    display(q);
   return 0;
}