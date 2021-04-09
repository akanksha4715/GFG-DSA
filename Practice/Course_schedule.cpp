#include<iostream>
#include<vector>
using namespace std;
bool isSafe(){

}
bool dfs(bool visited[],bool recst[],vector<vector<int>>& prerequisites,int src){
    visited[src]=1;
    recst[src]=1;
    //for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[src][1];
        if(!visited[u]){
            visited[u]=1;
            recst[u]=1;
            if(dfs(visited,recst,prerequisites,u))
            return true;
        }
        else if(recst[u])
        return true;
    //}
    recst[src]=0;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n=numCourses;
    bool visited[n],recst[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        recst[i]=0;
    }
        for(int i=0;i<n;i++)
        if(!visited[i]){
         if(dfs(visited,recst,prerequisites,i))
         return false;
        }
        return true; 
    }
int main(){

}
