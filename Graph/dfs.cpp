#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
void dfs(vector<int> adj[],bool visited[],int s){
    visited[s]=true;
    
    for(int x : adj[s]){
        if(!visited[x]){
        dfs(adj,visited,x);     
        }
    }
    
}
int main(){
    int v,u,e;
    int count=0;
    cin>>v;
    vector<int> adj[v];
    for(int i=0;i<v;i++){
        cin>>u>>e;
        adj[u].push_back(e);
        adj[e].push_back(u);
    }
    bool visited[v];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,visited,i);
            count++;
        }
    }
    cout<<count;
    return 0;
}