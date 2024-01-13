#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node{
    int num;
    int coeff;
    struct Node* next;
};
struct Node* start1=NULL;
struct Node* start2=NULL;
struct Node* start3=NULL;
struct Node* createPoly(struct Node* start){
    struct Node* ptr,*temp;
    int n,c;
    printf("Enter number:");
    scanf("%d",&n);
    printf("Enter its coefficient:");
    scanf("%d",&c);
    while(n!=-1){
        if(start==NULL){
            ptr=(struct Node*)malloc(sizeof(struct Node));
            ptr->num=n;
            ptr->coeff=c;
            ptr->next=NULL;
            start=ptr;
        }else {
            ptr=(struct Node*)malloc(sizeof(struct Node));
            ptr->num=n;
            ptr->coeff=c;
            ptr->next=NULL;
            temp=start;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
        }
        printf("Enter number:");
        scanf("%d",&n);
        printf("Enter its coefficient:");
        scanf("%d",&c);
    }
    return start;
}
struct Node* display(struct Node* start){
    struct Node* temp=start;
    while(temp->next!=NULL){
        printf("%dx%d + ",temp->num,temp->coeff);
        temp=temp->next;
    }
    printf("%dx%d\n",temp->num,temp->coeff);
    return start;
}
struct Node* addNode(struct Node* start,int n,int c){
    struct Node* ptr,*temp;
    if(start==NULL){
            ptr=(struct Node*)malloc(sizeof(struct Node));
            ptr->num=n;
            ptr->coeff=c;
            ptr->next=NULL;
            start=ptr;
        }else {
            ptr=(struct Node*)malloc(sizeof(struct Node));
            ptr->num=n;
            ptr->coeff=c;
            ptr->next=NULL;
            temp=start;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
        }
        return start;
}
struct Node* addPoly(struct Node* start1,struct Node* start2,struct Node* start3){
    struct Node* ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->coeff==ptr2->coeff){
            int sum=0;
            sum=ptr1->num+ptr2->num;
            start3=addNode(start3,sum,ptr1->coeff);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else if(ptr1->coeff>ptr2->coeff){
            start3=addNode(start3,ptr1->num,ptr1->coeff);
            ptr1=ptr1->next;
        }else{
            start3=addNode(start3,ptr2->num,ptr2->coeff);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        start3=addNode(start3,ptr1->num,ptr1->coeff);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        start3=addNode(start3,ptr2->num,ptr2->coeff);
        ptr2=ptr2->next;
    }
    return start3;
}
int main(){
    start1=createPoly(start1);
    start1=display(start1);
    start2=createPoly(start2);
    start2=display(start2);
    start3=addPoly(start1,start2,start3);
    start3=display(start3);
    return 0;
}