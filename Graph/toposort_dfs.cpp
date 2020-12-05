#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void dfs(vector<int> adj[], bool visited[],int src, stack<int> &st){
    visited[src]=true;
    for(int u:adj[src]){
        if(visited[u]==false){
            dfs(adj,visited,u,st);
        }
    }
    st.push(src);
}
int main(){
    int v, e;
    cin>>v>>e;
    bool visited[v];
    memset(visited,0,sizeof(visited));
    vector<int> adj[v];
    stack<int> st;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfs(adj,visited,i,st);
        }
    }
    while(st.empty()==false){
        int k=st.top();
        st.pop();
        cout<<k<<" ";
    }
   
    return 0;
}