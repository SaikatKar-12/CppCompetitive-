#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node{
    int data;
    struct Node* next;
};
struct queue{
    struct Node *f;
    struct Node *b;
};
void create_q(struct queue* q){
    q->f=NULL;
    q->b=NULL;
}
struct queue *push(struct queue* q,int val){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    if(q->f==NULL){
        temp->next=NULL;
        q->f=q->b=temp;
    }else{
        temp->next=NULL;
        q->b->next=temp;
        q->b=temp;
    }
    return q;
}
struct queue *pop(struct queue *q){
    if(q->f==NULL){
        printf("Queue is Empty!\n");
        return NULL;
    }else{
        struct Node* ptr;
        ptr=q->f;
        q->f=q->f->next;
        printf("the value being deleted is : %d\n",ptr->data);
        free(ptr);
    }
    return q;
}
struct queue *display(struct queue *q){
    if(q->f==NULL){
        printf("Queue is Empty!\n");
        return NULL;
    }else{
        struct Node* ptr;
        ptr=q->f;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    return q;
}
int peek(struct queue *q){
    if(q->f==NULL){
        printf("Queue is Empty!\n");
        return -1;
    }
    return q->f->data;
}
int main(){
    printf("hello\n");
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    // q->b=NULL;
    // q->f=NULL;
    create_q(q);
    q=push(q,1);
    q=push(q,2);
    q=push(q,3);
    q=push(q,4);
    q=push(q,5);
    q=push(q,6);
    q=display(q);
    q=pop(q);
    q=display(q);
    q=pop(q);
    q=display(q);
    printf("%d",peek(q));
    return 0;
}