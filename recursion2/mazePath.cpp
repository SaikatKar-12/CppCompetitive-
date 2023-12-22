#include<iostream>
using namespace std;
int maze(int sr, int sc,int er,int ec){
    if(sr>er || sc>ec) return 0;
    if(sc==ec && sr==er) return 1;
    int rightways=maze(sr,sc+1,er,ec);
    int downways=maze(sr+1,sc,er,ec);
    return rightways+downways;
}
void mazepath(int sr, int sc,int er,int ec,string s){
    if(sr>er || sc>ec) return;
    if(sc==ec && sr==er){
        cout<<s<<endl;
        return;
    } 
    mazepath(sr,sc+1,er,ec,s+'R');
    mazepath(sr+1,sc,er,ec,s+'D');
    
}
int main(){
    //cout<<maze(1,1,5,5);
    mazepath(1,1,3,3,"");
    return 0;
}