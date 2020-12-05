#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define S 4
using namespace std;
void prims(vector<vector<int> > graph, int v){
        int key[v],res=0,u,i;
        fill(key,key+v,INT16_MAX);
        key[0]=0;
        bool visited[v];
        //memset(visited,0,v);
        
        for(int count=0;count<v;count++){
            u=-1;
            for(i=0;i<v;i++){   
                if(!visited[i] && (u==-1 || key[i]<key[u]))
                u=i;
            }
            res=res+key[u];
            visited[u]=true;
            for(int j=0;j<v;j++){
                if(graph[u][j]!=0 && !visited[j])
                {
                    key[j]=min(key[j],graph[u][j]);
                }
            }
        }
        cout<<res;
}
int main(){
    int v;
    cin>>v;
    vector<vector<int>> graph;
   
    for(int i=0;i<v;i++){
         vector<int> v1;
        for(int j=0;j<v;j++){
            int u;
            cin>>u;        
            v1.push_back(u);
        }
        graph.push_back(v1);
    }
    prims(graph,S);
    return 0;
}