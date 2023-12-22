#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter  array size:";
    cin>>n;
    int minr,minc,maxr,maxc,count;
    minr=0;
    minc=0;
    count=1;
    maxr=n-1;
    maxc=n-1;
    int b[n][n];
    while(minr<=maxr && minc<=maxc){
        //right
        for(int i=minc;i<=maxc && count<=n*n;i++){
            b[minr][i]=count;
            count++;
        }
        minr++;
        //down
        for(int i=minr;i<=maxr && count<=n*n;i++){
            b[i][maxc]=count;
            count++;
        }
        maxc--;
        //left
        for(int i=maxc;i>=minc && count<=n*n;i--){
            b[maxr][i]=count;
            count++;
        }
        maxr--;
        //up
        for(int i=maxr;i>=minr && count<=n*n;i--){
            b[i][minc]=count;
            count++;
        }
        minc++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
