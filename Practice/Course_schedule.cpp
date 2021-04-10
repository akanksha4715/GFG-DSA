#include<iostream>
#include<vector>
using namespace std;
bool dfs(bool visited[],bool recst[],vector<int> adj[],int src){
    visited[src]=1;
    recst[src]=1;
    for(int u:adj[src]){
        if(!visited[u]){
            visited[u]=1;
            recst[u]=1;
            if(dfs(visited,recst,adj,u))
            return true;
        }
        else if(recst[u])
        return true;
    }
    recst[src]=0;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n=numCourses;
    vector<int> adj[n];
    for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    bool visited[n],recst[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        recst[i]=0;
    }
        for(int i=0;i<n;i++)
        if(!visited[i]){
         if(dfs(visited,recst,adj,i))
         return false;
        }
        return true; 
    }

