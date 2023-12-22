#include<iostream>
using namespace std;

int main(){
    int m, n;
    cout << "enter 1st array row and size:";
    cin >> m >> n;
    cout << "Enter  array elements:";
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i+j==m-1 || i==j){
                cout<<a[i][j];
            }else {
                cout<<" ";
            }
           
        }
         cout<<endl;
    }
    return 0;
}