#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
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
    bool flag=true;
    for(int i=1;i<=v.size()-1;i++){
        if(v[i-1]>v[i]){
            flag=false;
        }

    }
    if(flag==false) cout<<"array is not sorted";
    else cout<<"array is sorted";
    return 0;
}