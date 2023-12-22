#include<iostream>
using namespace std;

int main(){
    char ch;
    int ascii;
    cout<<"Enter a character:";
    cin>>ch;
    ascii=(int)ch;
    if(ascii>=65 && ascii<=90){
        cout<<"It is an upper case alphabet.";
        cout<<endl;
        if(ch=='A'|| ch=='E'|| ch=='I'|| ch=='O'|| ch=='U'){
            cout<<"It is a vowel.";
        }else{
            cout<<"It is a consonent.";
        }
    }else if(ascii>=97 && ascii<=122){
        cout<<"It is a lower case alphabet.";
        cout<<endl;
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
            cout<<"It is a vowel.";
        }else{
            cout<<"It is a consonent.";
        }
    }else if(ascii>=48 && ascii<=57){
        cout<<"It is a number.";
    }else{
        cout<<"It is a special character.";
    }
    return 0;
}