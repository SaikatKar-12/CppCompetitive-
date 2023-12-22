#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val=v;
        next=NULL;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=tail=NULL;
        size=0;
    }
    void InsertAtEnd(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void InsertAtBeg(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void InsertAtIdx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid syntax";
        else if(idx==0) InsertAtBeg(val);
        else if(idx==size) InsertAtEnd(val);
        else {
            Node* t=new Node(val);
            Node* temp=head;
            for(int i=1;i<idx;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }
    int getAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid syntax";
            return -1;
        } 
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else {
            Node* temp=head;
            for(int i=1;i<=idx;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }
    void deleteAtHead(){
        if(size==0){
            cout<<"List is empty";
            return;
        }
        head=head->next;
        size--;
    }
    void deleteAtTail(){
        if(size==0){
            cout<<"list is empty";
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }        
        temp->next=NULL;
        size--;
    }
    void deleteAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid index";
            return;
        }else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else{
            Node* temp=head;
            for(int i=1;i<idx;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
        }
    }
    void deleteMiddle(){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        //return head;
    }
};
Node *deleteMiddle(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast->next->next!=NULL && fast->next->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
    }
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
Node *deleteSameval(int val,Node *head){
    Node* temp=head;
    while(temp->next!=NULL){
        
    }
}
int main(){
   LinkedList ll;
   ll.InsertAtEnd(10);
   ll.display();
   ll.InsertAtEnd(20);
   ll.InsertAtEnd(20);
   ll.display();
   ll.deleteMiddle();
   ll.display();
//    cout<<ll.getAtIdx(2)<<endl;
//    ll.deleteAtHead();
//    ll.display();
//    ll.deleteAtTail();
//    ll.display();
//    ll.deleteAtIdx(2);
//    ll.display();
   Node* head1=deleteMiddle(ll.head);
   display(head1);
    return 0;
}