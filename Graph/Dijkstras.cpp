#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void dij(vector<vector<int>> graph, int v,int src){
    int i,j,count;
    vector<int> dist(v,INT16_MAX);
    dist[src]=0;
    bool vis[v];
    for(count=0;count<v;count++){
        int u=-1;
        for(i=0;i<v;i++){
            if(!vis[i] && (u==-1 || dist[i]<dist[u])){
                u=i;
            }
        }
        vis[u]=true;
        for(j=0;j<v;j++){
            if(graph[u][j]!=0 && !vis[j]){
                if(dist[j]>dist[u]+graph[u][j]){
                     dist[j]=dist[u]+graph[u][j];
                }
            }
        }
    
    }
    for(i=0;i<v;i++)
    cout<<dist[i]<<" ";
}
int main(){
    int v,u,src;
    cin>>v;
    vector<vector<int>> graph;
    for(int i=0;i<v;i++){
        vector<int> v1;
        for(int j=0;j<v;j++){
            cin>>u;
            v1.push_back(u);
        }
        graph.push_back(v1);
    }
    cin>>src;
    dij(graph,v,src);
    return 0;
}