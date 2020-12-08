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
struct Graph* creategraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->v = V; 
	graph->e = E; 
	graph->edge = new Edge[E]; 
	return graph; 
} 
bool bellman(struct Graph* graph,int src,bool cycle,vector<int> &dist){
    int v=graph->v;
    int e=graph->e;
    
    for(int count=0;count<v-1;count++){
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
    struct Graph* graph=creategraph(v,e);
    cout<<"Edges";
    for(int i=0;i<e;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        graph->edge[i].src=src;
        graph->edge[i].dest=dest;
        graph->edge[i].wt=wt;
    }
    // graph->edge[0].src = 0; 
	// graph->edge[0].dest = 1; 
	// graph->edge[0].wt = 1; 

	// // add edge 0-2 (or A-C) 
	// graph->edge[1].src = 0; 
	// graph->edge[1].dest = 2; 
	// graph->edge[1].wt = 4; 

	// // add edge 1-2 (or B-C) 
	// graph->edge[2].src = 1; 
	// graph->edge[2].dest = 2; 
	// graph->edge[2].wt = -3; 

	// // add edge 1-3 (or B-D) 
	// graph->edge[3].src = 1; 
	// graph->edge[3].dest = 3; 
	// graph->edge[3].wt = 2; 

	// // add edge 2-3 (or C-D) 
	// graph->edge[4].src = 2; 
	// graph->edge[4].dest = 3; 
	// graph->edge[4].wt = 3; 
    cout<<"Source?";
    cin>>s;
    vector<int> dist(v,INT16_MAX);
    dist[s]=0;
    cycle=bellman(graph,s,cycle,dist);
    if(cycle)
    cout<<"Cycle exists";
    else{
        cout<<"No cycle";
        print(dist,v);
    }
    return 0;
}