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
    //transpose
    for(int i=0;i<=m-1;i++){
        for(int j=i+1;j<=n-1;j++){
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
       
    }

      for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = m-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}