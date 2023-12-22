#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<climits>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int max1,max2;
    max1=INT_MIN;
    max2=INT_MIN;
    for(int i=0;str[i]!='\0';i++){
        int ascii=(int)str[i]-48;
        if(max1<ascii){
            max1=ascii;
        }else if(max2<ascii && max1!=ascii){
            max2=ascii;
        }
    }
    cout<<max1<<" "<<max2;
    return 0;
}