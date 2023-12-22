#include<iostream>
#include<vector>
using namespace std;

int main(){
    int grid[3][4]={{0,1,0,1},{1,1,0,0},{0,1,1,1}};
    for(int i=0;i<3;i++){
            if(grid[i][0]!=1){
                //flip
                for(int j=0;j<4;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }
                }
            }
        }
         cout<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int j=0;j<4;j++){
            int no1=0;
            int no0=0;
            for(int i=0;i<3;i++){
                if(grid[i][j]==0) no0++;
                else no1++;
            }
            if(no0>no1){
                //flip
                for(int i=0;i<3;i++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }
                }
            }
        }
            cout<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}