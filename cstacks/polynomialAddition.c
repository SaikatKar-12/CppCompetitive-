#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};
struct Node *start1 = NULL;
struct Node *start2=NULL;
struct Node *head3=NULL;
struct Node *create_ll(struct Node *start)
{
    int cval;
    int eval;
    struct Node *new_node;
    struct Node *ptr;
    printf("Enter both 0 to end ");
    printf("Enter your coeff: ");
    scanf("%d", &cval);
    printf("Enter your exponent: ");
    scanf("%d", &eval);

    while (cval != 0 || eval!=0)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->coeff = cval;
        new_node->exp=eval;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
    printf("Enter both 0 to end ");
    printf("Enter your coeff: ");
    scanf("%d", &cval);
    printf("Enter your exponent: ");
    scanf("%d", &eval);
    }
    return start;
}
struct Node* display(struct Node* start){
    struct Node* temp;
    temp=start;
    while(temp->next){
        printf("%dx^%d + ",temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf("%dx^%d \n",temp->coeff,temp->exp);
}
struct Node* deleteEnd(struct Node *start){
    struct Node *ptr;
    ptr=start;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    return start;
}
struct Node* insert(struct Node* head,int co,int expo)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->coeff=co;
    temp->exp=expo;
    if(head==NULL )
    {
        head=temp;
        temp->next=NULL;
    }
    else
    {
        struct Node* temp1=head;
        while(temp1->next!=NULL )
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->next=NULL;
    }
    return head;
}
struct Node* polyAddition(struct Node *head1,struct Node *head2,struct Node *head3){
    struct Node *ptr1,*ptr2;
    ptr1=head1;
    ptr2=head2;
    while(ptr1 && ptr2){
        if(ptr1->exp==ptr2->exp){
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }else if(ptr1->exp>ptr2->exp){
            head3=insert(head3,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }else{
            head3=insert(head3,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1){
        head3=insert(head3,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2){
        head3=insert(head3,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }
    return head3;
}
    int main()
    {   
        start1=create_ll(start1);
        start2=create_ll(start2);
        start1=display(start1);
        start2=display(start2);
        head3=polyAddition(start1,start2,head3);
        head3=display(head3);
        return 0;
    }