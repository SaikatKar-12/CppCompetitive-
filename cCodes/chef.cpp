#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	int a,b;
	cin>>t;
	for(int i=0;i<t;i++){
	    cin>>a>>b;
	    if(a%b==0){
	        cout<<0<<endl;
	        continue;
	    }
	    int temp;
	    if(a>b){
	      temp=a%b;   
	    }else{
	        temp=b%a;
	    }
	    int ans=b-temp;
	    cout<<ans<<endl;
	}
	return 0;
}
