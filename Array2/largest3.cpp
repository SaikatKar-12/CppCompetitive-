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
    int max1, max2, max3;
    max1 = max2 = max3 = INT_MIN;
    for(int i=0;i<=v.size()-1;i++){
        if(max1<v[i]) max1=v[i];
    }
     for(int i=0;i<=v.size()-1;i++){
        if(max2<v[i] && max1!=v[i]) max2=v[i];
    }
     for(int i=0;i<=v.size()-1;i++){
        if(max3<v[i] && max2!=v[i] && max1!=v[i]) max3=v[i];
    }
    cout<<"max1="<<max1<<" "<<"max2="<<max2<<" "<<"max3="<<max3;
    return 0;
}
// #include <iostream>
// using namespace std;
// int main() {
// int arr[5]={10,3,1,21,3};
// int max, max2, max3;
// max3 = max = max2 = arr[0];
// for(int i = 0; i < 5; i++){
// if (arr[i] > max){
// max3 = max2;
// max2 = max;
// max = arr[i];
// }
// else if (arr[i] > max2){
// max3 = max2;
// max2 = arr[i];
// }
// else if (arr[i] > max3)
// max3 = arr[i];
// }
// cout<<endl<<"Three largest elements of the array are "<<max<<", "<<max2<<",
// "<<max3;
// return 0;
// }