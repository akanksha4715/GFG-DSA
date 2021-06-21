#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i]!=0) continue;
            q.push(i);color[i]=1;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto x : graph[u]){
                    if(color[x]==color[u])
                        return false;
                    else if(!color[x]){
                        color[x]=-color[u];
                        q.push(x);
                    }
                }
            }
        }
        return true;
    }
};