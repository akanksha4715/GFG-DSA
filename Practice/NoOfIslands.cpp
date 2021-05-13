#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int count){
        int n=grid.size();
        return ( i>=0 && j>=0 && i<n && j<count && !visited[i][j] && grid[i][j]=='1' );
    }
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int count){
        int n=grid.size();
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        while(!q.empty()){
            cout<<"two";
            int u=q.front().first;
            int v=q.front().second;
            visited[u][v]=1;
            q.pop();
            for(int k=0;k<4;k++){
                if(isSafe(grid,visited,u+row[k],v+col[k],count)){
                    cout<<"3";
                    q.push( make_pair(u+row[k],v+row[k]) );
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int ans=0,count=grid[0].size();
        vector<vector<bool>> visited;
        for(int i=0;i<n;i++){
            vector<bool> v;
            for(int j=0;j<count;j++){
                v.push_back(0);
            }
            visited.push_back(v);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<count;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(grid,visited,i,j,count);
                    ans++;
                }
            }
        }
        return ans;
    }
    int main(){
        vector<vector<char>> grid={
            {'1','1','1','1','0'},
            {'1','1','1','1','0'},
            {'1','1','1','1','0'},
            {'1','1','1','1','0'},
            {'1','1','1','1','0'}
        };
    cout<<numIslands(grid);
        return 0;
    }