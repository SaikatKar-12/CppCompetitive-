#include<iostream>
using namespace std;

int main(){
     int m,n;
    cout << "Enter number:";
    cin >>m>> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==1||j==1||i==m||j==n){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }

        cout << endl;
    }
    return 0;
}