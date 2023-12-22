#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int odd_sum=0,even_sum=0;
    vector<int> v;
    int n;
    cout << "Enter array size:";
    cin >> n;
    cout << "Enter array elements:";
    for (int i = 0; i <= n - 1; i++)
    {
        int q;
        cin >> q;
        v.push_back(q);
    }
    for(int i = 0; i <= n - 1; i++){
        if(i%2==0) v[i]=v[i]+10;
        else v[i]=v[i]*2;
    }
     for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    return 0;
}