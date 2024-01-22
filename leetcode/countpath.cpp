#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> g(n+1);
        for(int i=2;i<=n;i++)
        {
            g[i].push_back(i-1);
            g[i-1].push_back(i);
        }
        
        g[x].push_back(y);
        g[y].push_back(x);
        
        vector<int> ans(n);
        for(int i=1;i<=n;i++)
        {
            vector<int> dist(n+1,1e9);
            dist[i]=0;
            queue<int> bfs;
            bfs.push(i);
            
            while(!bfs.empty())
            {
                int node=bfs.front();
                bfs.pop();
                
                for(auto child : g[node])
                {
                    if(dist[child]>dist[node]+1)
                    {
                        //cout<<dist[child]<<" "<<dist[node]<<" ";
                        dist[child]=dist[node]+1;
                        cout<<dist[child]<<" ";
                        bfs.push(child);
                    }
                }
            }
            cout<<endl;
            for(int i=1;i<=n;i++)
            {
                if(dist[i])
                    ans[dist[i]-1]++;
            }
        }
        return ans;
    }
int main(){
    vector<int> ans=countOfPairs(5,2,4);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    //cout<<(1e9)>(1e9+1);
    return 0;
}