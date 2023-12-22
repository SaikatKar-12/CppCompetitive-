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
class Deque{
public:
    Node* head;
    Node* tail;
    int size;
    Deque(){
        head=tail=NULL;
        size=0;
    }
    void pushBack(int val){
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
    void pushFront(int val){
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
    

    void popFront(){
        if(size==0){
            cout<<"List is empty";
            return;
        }
        head=head->next;
        head->prev=NULL;
        size--;
    }
    void popBack(){
        if(size==0){
            cout<<"list is empty";
            return;
        }
        Node* temp=tail->prev;      
        temp->next=NULL;
        tail=temp;
        size--;
    }
    
};
int main(){
    Deque dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.display();
    dq.pushFront(50);
    dq.display();
    dq.popBack();
    dq.display();
    dq.popFront();
    dq.display();
}