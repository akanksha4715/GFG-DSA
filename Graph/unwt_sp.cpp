#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
void dist(vector<int> adj[],int src, int distance[],int n){
    bool visited[n];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(src);
    visited[src]=true;
    distance[src]=0;
    while(q.empty()==false){
        int u =q.front();
        q.pop();
        for(int v: adj[u]){
            if(visited[v]==false){
                distance[v]=distance[u]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }
    for(int j=0;j<n;j++){
        cout<<distance[j];
    }

}
int main(){
    int v,e,src;
    cin>>v>>e;
    int distance[v];
    memset(distance,0,sizeof(distance));
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>src;
    dist(adj,src,distance,v);
    return 0;
}