#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* start1=NULL;
struct Node* start2=NULL;
struct Node* start3=NULL;
struct Node* create_poly(struct Node* start){
    struct Node* ptr,*temp;
    int e;
    int c;
    printf("Enter exponent or -1 to exit :");
    scanf("%d",&e);
    if(e==-1) return NULL;
    printf("Enter coefficient:");
    scanf("%d",&c);
    while(e!=-1){
        ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->coeff=c;
        ptr->exp=e;
        ptr->next=NULL;
        if(start==NULL){
            start=ptr;
        }else{
            temp=start;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=ptr;
        }
        printf("Enter exponent or -1 to exit :");
        scanf("%d",&e);
        if(e==-1) break;
        printf("Enter coefficient:");
        scanf("%d",&c);
    }
    return start;
}
void display(struct Node* start){
    struct Node* temp=start;
    while(temp->next){
        printf("%dx%d + ",temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf("%dx%d\n",temp->coeff,temp->exp);
}
struct Node* addNode(struct Node* start,int c,int e){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    ptr->coeff=c;
    ptr->exp=e;
    ptr->next=NULL;
    if(start==NULL){
        start=ptr;
    }else{
        temp=start;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=ptr;
    }
    return start;
}
struct Node* add_poly(struct Node* start1,struct Node* start2,struct Node* start3){
    struct Node* ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    while(ptr1 && ptr2){
        if(ptr1->exp==ptr2->exp){
            int sum=ptr1->coeff+ptr2->coeff;
            start3=addNode(start3,sum,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else if(ptr1->exp>ptr2->exp){
            start3=addNode(start3,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }else{
            start3=addNode(start3,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1){
        start3=addNode(start3,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2){
        start3=addNode(start3,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }
    return start3;
}
int main() {
    start1=create_poly(start1);
    display(start1);
    start2=create_poly(start2);
    display(start2);
    start3=add_poly(start1,start2,start3);
    display(start3);
    return 0;
}