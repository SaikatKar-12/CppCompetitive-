#include<iostream>
#include<string.h>
using namespace std;
class book{
    public: 
        int price;
        string name;
    int isprice(int n){
        if(price<=n) return 1;
        else return 0;
    }
    int isname(string s){
        if(s==name) return 1;
        else return 0;
    }
    
};
int main(){
    book harry;
    harry.price=350;
    harry.name="Harry Potter";
    cout<<harry.isprice(90)<<endl;
    cout<<harry.isname("Harry Potter");
    return 0;
}