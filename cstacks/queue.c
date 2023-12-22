#include<stdio.h>
#include<malloc.h>
struct queue{
    int front;
    int back;
    int size;
    int *arr;
};
int qsize(struct queue* q){
    return (q->back)-(q->front);
}
void push(struct queue* q,int val){
    if(qsize(q)==q->size) {
        printf("Queue is full!");
    }
    else{       
            q->arr[q->back]=val;
            q->back++;
    }
}
void pop(struct queue* q){
    if(qsize(q)==0){
        printf("Queue is empty!");
    }
    else{
        q->front++;
    }
}
int front(struct queue* q){
    if(qsize(q)==0){
        printf("Queue is empty!");
    }else{
        return q->arr[q->front];
    }
}
int back(struct queue* q){
    if(qsize(q)==0){
        printf("Queue is empty!");
    }else{
        return q->arr[q->back-1];
    }
}
void display(struct queue* q){
    for(int i=q->front;i<q->back;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}
int main(){
    struct queue q;
    q.size=10;
    q.front=0;
    q.back=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    push(&q,1);
    push(&q,2);
    push(&q,3);
    push(&q,4);
    display(&q);
    pop(&q);
    display(&q);
    printf("\n%d %d",q.front,q.back);
}