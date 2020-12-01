#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define R 5 
#define C 5 
bool issafe(int i,int j,int mat[5][5],bool visited[5][5]){
return (
    (i>=0) && (j>=0) &&
    (i<5) && (j<5) &&
    (mat[i][j]) && (!visited[i][j])
);
}
int bfs_count(int mat[5][5],bool visited[5][5],int si,int sj){
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
    cout<<maxx;
    return maxx;
}
int main(){
    int r=5,c=5,count=0;
    bool visited[5][5];
    int maxx=0;
memset(visited,0,sizeof(visited));
int mat[5][5]={
    {1,1,0,0,0},
    {0,1,0,0,1},
    {1,0,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
};
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(mat[i][j] && !visited[i][j]){
           int count= bfs_count(mat,visited,i,j);
           maxx = max(maxx,count);
        }   
    }    
}
cout<<maxx;
return 0;
}