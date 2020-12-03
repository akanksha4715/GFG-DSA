#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void bfs(vector<int> adj[], bool visited[], int indegree[],  int v){
   cout<<"\n";
    queue<int> q;
    for(int i=0;i<v;i++)
        if(indegree[i]==0){
        q.push(i);
        
        }
        while(q.empty()==false){
            int v=q.front();
            q.pop();
            
            cout<<v<<" ";
            for(int u:adj[v]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                   
                }

        }
        }
        

}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    int indegree[v];
    bool visited[v];
    memset(visited,0,v);
    memset(indegree,0,sizeof(indegree));
    //vector<int> indegree(v,0);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    
    bfs(adj,visited,indegree,v);
    return 0;
}