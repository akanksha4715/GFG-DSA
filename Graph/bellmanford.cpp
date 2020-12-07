#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
    int src;
    int dest;
    int wt;
};
struct Graph
{
    int v,e;
    struct Edge* edge;
    
};
struct Graph* creategraph(int v,int e){
    struct Graph* graph = new Graph;
    graph->v=v;
    graph->e=e;
    struct Edge* edge = new Edge[e];
    return graph;
}
bool bellman(struct Graph* graph,int src,bool cycle,vector<int> dist){
    int v=graph->v;
    int e=graph->e;
    
    for(int count=0;count<v;count++){
        for(int j=0;j<e;j++){
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int wt=graph->edge[j].wt;
            if(dist[v]>dist[u]+wt)
             dist[v]=dist[u]+wt;
        }
    }
    for(int j=0;j<e;j++){
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int wt=graph->edge[j].wt;
            if(dist[v]>dist[u]+wt)
             {
                 cycle=true;;
                 break;
             }
        }
        return cycle;
}
void print(vector<int> dist,int v){
    printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < v; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
}
int main(){
    int v,e,s;
    cin>>v>>e;
    bool cycle=false;
    int src,dest,wt;
    struct Graph* graph=creategraph(v,e);
    cout<<"Edges";
    for(int i=0;i<e;i++){
        cin>>src>>dest>>wt;
        graph->edge[i].src=src;
        graph->edge[i].dest=dest;
        graph->edge[i].wt=wt;
    }
    cout<<"Source?";
    cin>>s;
    vector<int> dist(v,INT16_MAX);
    dist[src]=0;
    cycle=bellman(graph,s,cycle,dist);
    if(cycle)
    cout<<"Cycle exists";
    else{
        print(dist,v);
    }
    return 0;
}