#include<iostream>
using namespace std;

int main(){
    int n;
   // bool k;
    cout<<"Enter number:";
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     if(i%2==0){
    //         k=true;
    //     }else{
    //         k=false;
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<k<<" ";
    //         k=!k;
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0) cout<<"1";
            else cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}