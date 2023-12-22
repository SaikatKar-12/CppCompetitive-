#include<iostream>
using namespace std;
int global=5;
int main(){
    cout<<"size of char:"<<sizeof(char)<<endl;
    cout<<"size of float:"<<sizeof(float)<<endl;
    cout<<"size of double:"<<sizeof(double)<<endl;
    cout<<"size of int:"<<sizeof(int)<<endl;
    cout<<"size of bool:"<<sizeof(bool)<<endl;
    int global=50;
    cout<<global;
    cout<<::global;//scope resoluter operator for using global variable
    return 0;
}
