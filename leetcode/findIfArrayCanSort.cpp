#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int minimumPushes(string s) {
        unordered_map<int,string> mp;
        int j=2;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(j)==mp.end()){
                ans++;
                string c="";
                c+=s[i];
                mp[j]=c;
            }else{
                //cout<<"hello";
                string c=mp[j];
                c=c+s[i];
                mp[j]=c;
                cout<<c<<" ";
                if(c.size()==2) ans=ans+2;
                else if(c.size()==3) ans=ans+3;
                else if(c.size()==4) ans=ans+4;
                else ans=ans+5;
            }
            cout<< j <<" ";
            j++;
            if(j==10) j=2;
        }
        cout<<endl;
        return ans;
    }
int main(){
    cout<<minimumPushes("amrvxnhsewkoipjyuclgtdbfq");
    return 0;
}