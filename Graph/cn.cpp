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
    
    int num;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) { 
        vector<bool> v2; 
        for (int j = 0; j < n; j++) { 
            
            v2.push_back(0);     
        } 
        visited.push_back(v2); 
    }
    vector<vector<int> > mat; 
    for (int i = 0; i < n; i++) { 
        vector<int> v1; 
        for (int j = 0; j < n; j++) { 
            cin>>num;
            v1.push_back(num);     
        } 
        mat.push_back(v1); 
    }
    cin>>k;
for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] && !visited[i][j]){
                count= bfs_count(mat,visited,i,j);
                if(count==k){
                    cout<<i<<" "<<j<<"\n";
                    break;
                }
                }   
        }   
        if(count==k)
        break; 
}
}
return 0;
}