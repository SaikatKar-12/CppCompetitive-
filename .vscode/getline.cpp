#include<iostream>
using namespace std;

int main(){
    string text;
    int age;
    cout<<"what is your age?"<<endl;
    cin>>age;
    cin.ignore();
    cout<<"what is your name?"<<endl;
    getline(cin,text);
    cout<<"hello "<<text<<endl;
    return 0;
}