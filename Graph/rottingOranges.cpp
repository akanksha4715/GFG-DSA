#include<bits/stdc++.h>
using namespace std;


    bool isSafe(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        return i>=0 && i<n && j>=0 && j<m && grid[i][j]==1;
    }
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>> q){
        int count=-1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int x=u+row[j];
                    int y=v+col[j];
                    if(isSafe(x,y,grid)){
                        grid[x][y]=2;
                        q.push(make_pair(x,y));
                    }
                }
            }
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
                    q.push(make_pair(i,j));
                }
            }
        }
        int ans=bfs(grid,q);
        
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1)
                        return -1;
                }
            }
        if(ans==-1) ans=0;
        return ans;
    }

    
    int main(){
        vector<vector<int>> grid={
                                // {2,1,0},
                                // {0,0,0},
                                // {2,1,1},
                                // {1,0,2}
                                {1},{2}
                                    };
        cout<<orangesRotting(grid);
    }