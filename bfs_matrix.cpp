#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int bfs_count(int mat[5][5],bool visited[5][5],int si,int sj){
    
}
int main(){
    int r=5,c=5;
bool visited[5][5];
memset(visited,0,sizeof(visited));
int mat[5][5]={
    {1,1,0,0,0},
    {0,1,0,0,1},
    {1,0,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
};
for(int i=0;i,r;i++){
    for(int j=0;j<c;j++){
        if(mat[i][j] && !visited[i][j]){
           int count= bfs_count(mat,visited,i,j);
        }
    }
}
return 0;
}