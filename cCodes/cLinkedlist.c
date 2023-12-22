#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;
struct Node *create_ll(struct Node *start)
{
    int val;
    struct Node *new_node;
    struct Node *ptr;
    printf("Enter -1 to end ");
    printf("Enter your data: ");
    scanf("%d", &val);

    while (val != -1)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
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
    printf("Enter your data: ");
    scanf("%d", &val);
    }
    return start;
}
struct Node* InsertAt(int idx,struct Node* start){
    int val;
    struct Node *new_node,*ptr;
    printf("Enter your data: ");
    scanf("%d", &val);
    new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
            ptr=start;
            for(int i=1;i<idx;i++){
                ptr=ptr->next;
            }
            new_node->next=ptr->next;
            ptr->next=new_node;
        return start;
}
    struct Node *display(struct Node * start)
    {
        struct Node *ptr=start;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
                ptr=ptr->next;
            }
            printf("\n");
            return start;
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
struct Node* mergeList(struct Node* a,struct Node* b){
    struct Node* dummy=(struct Node *)malloc(sizeof(struct Node));
    struct Node* temp=dummy;
    while(a && b){
        if(a->data<=b->data){
            temp->next=a;
            a=a->next;
            temp=temp->next;
        }else{
            temp->next=b;
            b=b->next;
            temp=temp->next;
        }
    }
    if(a==NULL) temp->next=b;
    else temp->next=a;
    return dummy->next;
}

struct Node* sortList(struct Node* head){
    if(head==NULL || head->next==NULL) return head;
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct Node* a=head;
    struct Node* b=slow->next;
    slow->next=NULL;
    a=sortList(a);
    b=sortList(b);
    struct Node* c=mergeList(a,b);
    return c;
}
struct Node* reverseList(struct Node* head){
    if(head==NULL || head->next==NULL) return head;
    struct Node* prev=NULL;
    struct Node* curr=head;
    struct Node* Next=NULL;
    while(curr){
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    return prev;
}
    int main()
    {
        int opt;
        int idx;
        printf("*****Main Menu******\n");
        printf("1.create linked list\n");
        printf("2.display\n");
        printf("3.insert at index\n");
        printf("4.Delete end\n");
        printf("5.Sort List\n");
        printf("6.Reverse List\n");
        printf("7.exit\n");
        while (opt != 7)
        {
            printf("Enter your option: ");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                start = create_ll(start);
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d",&idx);
                start=InsertAt(idx,start);
                break;
            case 4:
                start=deleteEnd(start);
                break;
            case 5:
                start=sortList(start);
                break;
            case 6:
                start=reverseList(start);
                break;
            // case 3:
            //     start = insertAtbeg(start);
            //     break;
            // case 4:
            //     printf("Enter a index: ");
            //     scanf("%d", &idx);
            //     start = deleteAt(idx, start);
            //     break;
            // case 5:
            //     break;
            }
        }

        return 0;
    }