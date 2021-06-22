#include<bits/stdc++.h>
using namespace std;
class Solution {
public: vector<int> ans;
    bool dfs(vector<int> adj[],vector<bool> &visited,vector<bool> &recst,int src){
        visited[src]=1;
    recst[src]=1;
    for(int u:adj[src]){
        if(!visited[u]){
            visited[u]=1;
            recst[u]=1;
            if(dfs(adj,visited,recst,u))
            return true;
        }
        else if(recst[u])
        return true;
    }
    recst[src]=0;
        ans.push_back(src);
       cout<<src<<" ";
    return false;
        
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n,0);
        vector<bool> recst(n,0);
       
        int len=prerequisites.size();
        vector<int> adj[n];
        if(len==0)
        {
            for(int i=0;i<n;i++)
                ans.push_back(i);
            return ans;
        }
        for(int i=0;i<len;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                if(dfs(adj,visited,recst,i))
                    return {};
            }
        }
        
        return ans;
    }
};