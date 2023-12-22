#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int v){
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class DLL{
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
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
            temp->prev=tail;
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
    void displayrev(){
        Node* temp=tail;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
    void InsertAtBeg(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }else{
            temp->next=head;
            head->prev=temp;
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
            t->prev=temp;
            t->next->prev=t;
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
        head->prev=NULL;
        size--;
    }
    void deleteAtTail(){
        if(size==0){
            cout<<"list is empty";
            return;
        }
        Node* temp=tail->prev;      
        temp->next=NULL;
        tail=temp;
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
            temp->next->prev=temp;
            size--;
        }
    }
};
int main(){
    DLL list;
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtEnd(40);
    list.display();
    list.InsertAtBeg(50);
    list.InsertAtIdx(2,70);
    list.display();
    list.displayrev();
    list.deleteAtHead();
    list.display();
    list.deleteAtTail();
    list.display();
    list.deleteAtIdx(1);
    list.display();
    list.displayrev();
    return 0;
}