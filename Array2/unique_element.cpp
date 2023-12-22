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
    
    for(int i=0;i<=v.size()-1;i++){
        int count=0;
        for(int j=0;j<=v.size()-1;j++){
            if(i!=j && v[i]==v[j]){
                count++;
            }
        }
        if(count==0){
            cout<<v[i];
            break;
        }
    }
    return 0;
}