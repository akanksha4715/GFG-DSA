#include<bits/stdc++.h>
using namespace std;

    bool isSafe(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        return i>=0 && i<n && j>=0 && j<n && grid[i][j]==1;
    }
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>> q){
        int count=0;int flag;int x=0;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        while(!q.empty()){
                //cout<<"here";
            int n=q.size();
            for(int i=0;i<n;i++){
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                //cout<<u<<" "<<v<<endl;
                flag=0;
                for(int j=0;j<4;j++){
                    int x=u+row[j];
                    int y=v+col[j];              
                    if(isSafe(x,y,grid)){
                        flag=1;
                        grid[x][y]=2;
                        q.push(make_pair(x,y));
                        
                    }
                    x= x | flag;
                    //cout<<x<<endl;   
                }
                
                //cout<<u<<" "<<v<<" "<<count<<endl;
            }
             if(x!=0)
                count++;
        }
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    // cout<<i<<j<<endl;
                    q.push(make_pair(i,j));
                }
            }
        }
        //cout<<1;
        int count=bfs(grid,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
    }
    int main(){
        vector<vector<int>> grid={
                                {2,1,0},
                                {0,0,0},
                                {2,1,1},
                                {1,0,2}
                                    };
        cout<<orangesRotting(grid);
    }