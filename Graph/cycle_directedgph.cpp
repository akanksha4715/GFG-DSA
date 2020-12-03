#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
bool Dfs(vector<int> adj[],int s,bool visited[], bool recst[]){
    recst[s]=true;
    visited[s]=true;
    for(int u: adj[s]){
        if(visited[u]==false){
            visited[u]=true;
            recst[u]=true;
            if(Dfs(adj,u,visited,recst))
            return true;
        } 
        else if(recst[u])
        {
            
            return true;
        }
        
    }
    recst[s]=false;
    return false;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    bool visited[v];
    bool recst[v];
    memset(visited,0,v);
    memset(recst,0,v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int k=0;k<v;k++){
        if(visited[k]==false){
            if(Dfs(adj,k,visited,recst))
            cout<<"Exists";
            else
            {
                cout<<"No";
            }
        }
    }
    return 0;
}