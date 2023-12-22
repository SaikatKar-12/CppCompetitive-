#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "enter 1st array row and size:";
    cin >> m >> n;
    cout << "Enter  array elements:";
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << endl;
    int minr,minc,maxr,maxc;
    minr=0;
    minc=0;
    maxr=m-1;
    maxc=n-1;
    while(minr<=maxr && minc<=maxc){
        //right
        for(int i=minc;i<=maxc;i++){
            cout<<a[minr][i]<<" ";
        }
        minr++;
        if(minr>maxr || minc>maxc) break;
        //down
        for(int i=minr;i<=maxr;i++){
            cout<<a[i][maxc]<<" ";
        }
        maxc--;
        if(minr>maxr || minc>maxc) break;
        //left
        for(int i=maxc;i>=minc;i--){
            cout<<a[maxr][i]<<" ";
        }
        maxr--;
        if(minr>maxr || minc>maxc) break;
        //up
        for(int i=maxr;i>=minr;i--){
            cout<<a[i][minc]<<" ";
        }
        minc++;
    }
    return 0;
}
