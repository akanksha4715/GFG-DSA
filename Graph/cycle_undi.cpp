#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
bool Dfs(vector<int> adj[],int s,bool visited[],int parent){
    visited[s]=true;
    for(int u: adj[s]){
        if(visited[u]==false){
            visited[u]=true;
            if(Dfs(adj,u,visited,s))
            return true;
            
        }
        else if(u!=parent)
            return true;
    }
    return false;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    bool visited[v];
    memset(visited,0,v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int k=0;k<v;k++){
        if(visited[k]==false){
            if(Dfs(adj,k,visited,-1))
            cout<<"Exists";
            else
            {
                cout<<"No";
            }
        }
    }
    return 0;
}