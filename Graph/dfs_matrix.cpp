#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool issafe(int i,int j,int mat[5][5],bool visited[5][5]){
    return (
        (i>=0) && (j>=0) && (i<5) && (j<5) && 
        (mat[i][j] && !visited[i][j])
    );
}
void dfs(int mat[5][5],bool visited[5][5],int i,int j){
    int row[]={-1,-1,-1,0,0,1,1,1};
    int col[]={1,0,-1,1,-1,1,0,-1};
    visited[i][j]=true;
    cout<<i<<j<<"\n";
    for(int k=0;k<8;k++){
    if(issafe(i+row[k],j+col[k],mat,visited)){
        dfs(mat,visited,i+row[k],j+col[k]);
    }
    }
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
            dfs(mat,visited,i,j);
            count++;
        }
    }
}
cout<<"No is"<<count;
return 0;
}