#include<bits/stdc++.h>
using namespace std;
int bfs(vector<int> adjlist[],int src,bool visited[]){
    queue<int> q;int count=1;
    q.push(src);
    visited[src]=true;
    while(q.empty()==false){
        int u =q.front();
        //cout<<u;
        q.pop();
        for(int x: adjlist[u]){
            if(visited[x]==false){
            q.push(x);
            visited[x]=true;
            count++;
            }   
        }
    }
    return count;
}
int bfs_count(vector<int> adjlist[], int v){
    bool visited[v];int maxx=0,count;
    for(int i=0;i<v;i++)
    visited[i]=false;
    for(int i=0;i<v;i++){
        if(visited[i]==false)
            {
                int count=bfs(adjlist,i,visited);
                maxx=max(maxx,count);
                }
    }
    return maxx;
}
int main(){
    int v,u,e;
    cin>>v;
    vector<int> adjlist[v];
    for(int i=0;i<v;i++){
        cin>>u>>e;
        adjlist[e].push_back(u);
        adjlist[u].push_back(e);
    }
    cout<<"Total graphs="<< bfs_count(adjlist,v);
    return 0;
}
// void addEdge(vector<int> adj[], int u, int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// int main() 
// { 
// 	int V=7;
// 	vector<int> adj[V];
// 	addEdge(adj,0,1); 
// 	addEdge(adj,0,2); 
// 	addEdge(adj,2,3); 
// 	addEdge(adj,1,3); 
// 	addEdge(adj,4,5);
// 	addEdge(adj,5,6);
// 	addEdge(adj,4,6);

// 	cout << "Number of max islands: "<<bfs_count(adj,V); 

// 	return 0; 
// } 
