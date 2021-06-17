#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
bool issafe(int i,int j,vector<vector<int>> mat,vector<vector<bool>> visited){
return (
    (i>=0) && (j>=0) &&
    (i<5) && (j<5) &&
    (mat[i][j]) && (!visited[i][j])
);
}
int bfs_count(vector<vector<int>> mat,vector<vector<bool>> visited,int si,int sj){
    int row[]={-1,-1,-1,0,1,1,1,0};
    int col[]={-1,0,1,1,1,0,-1,-1};
    int maxx=1;
    queue<pair<int,int>> q;
    q.push(make_pair(si,sj));
    visited[si][sj]=true;
    while(q.empty()==false){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        visited[i][j]=true;
        for(int k=0;k<8;k++){
            if(issafe(i+row[k],j+col[k],mat,visited)){
                q.push(make_pair(i+row[k],j+col[k]));
                visited[i+row[k]][j+col[k]]=true;
                maxx++;
            }
    }
    }
    
    return maxx;
}
int main(){
    int t,count;
    cin>>t;
    for(int p=0;p<t;p++){
    int k;
    vector<vector<bool> > visited; 
    int maxim=0;
    int num;
    int n1,n2;
    cin>>n1>>n2;
for (int i = 0; i < n1; i++) { 
        vector<bool> v2; 
        for (int j = 0; j < n2; j++) { 
            
            v2.push_back(0);     
        } 
        visited.push_back(v2); 
    }
vector<vector<int> > mat; 
    for (int i = 0; i < n1; i++) { 
        vector<int> v1; 
        for (int j = 0; j < n2; j++) { 
            cin>>num;
            v1.push_back(num);     
        } 
        mat.push_back(v1); 
    }
    cin>>k;
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        if(mat[i][j] && !visited[i][j]){
           count= bfs_count(mat,visited,i,j);
           maxim=max(maxim,count);
           }
        }   
    }   
    cout<<maxim;
}
return 0;
}
/* *******Without Extra Space ************ */
class Solution {
public:
    bool isSafe(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        return i>=0 && j>=0 && i<n && j<m && grid[i][j]=='1';
    }
    void bfs(vector<vector<char>>& grid,int i,int j){
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        while(!q.empty()){
            int u=q.front().first;
            int v=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=u+row[i];
                int y=v+col[i];
                if(isSafe(x,y,grid)){
                    grid[x][y]='*';
                    q.push(make_pair(x,y));
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    grid[i][j]='*';
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
};