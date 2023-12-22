#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(6);
    v.push_back(3);
    v.push_back(7);
    v.push_back(0);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    // bool flag;
    // for(int i=0;i<=v.size()-1;i++){
    //     flag=true;
    //     for(int j=0;j<=v.size()-1;j++){

    //         if( i!=j && v[i]==v[j]){
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag==true){
    //         cout<<"Non repeating element is "<<i;
    //         break;
    //     }
    // }
    // if(flag==false) cout<<"None";
    int n=v.size();
    for (int i = 0; i < n; i++)
    {
        int j;
        // Checking if ith element is present in array
        for (j = 0; j < n; j++)
            if (i != j && v[i] == v[j])
                break;
        if (j == n)
        {
            cout << v[i];
            break;
        }
    }
    return 0;
}