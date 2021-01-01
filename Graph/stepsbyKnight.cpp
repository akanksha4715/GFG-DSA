#include <bits/stdc++.h> 
#include<vector>
using namespace std; 
struct block{
    int x;
    int y;
    int dis;
    block(){}
    block(int a,int b,int c)
    {
        x=x;
        y=b;
        dis=c;
    }
};
bool safe(int i,int j,int n){
    if( (i>=1) && (j>=1) && (i<=n) && (j<=n))
    return true;
    return false;
}
int minStepToReachTarget(int src[],int dest[],int n){
    int row[] ={-2,-2,-1,1,2,2,1,-1};
    int col[]={-1,1,2,2,1,-1,-2,-2};
    queue<block> q;
    bool visited[n + 1][n + 1]; 
    int minn=INT16_MAX;
	// make all cell unvisited 
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			visited[i][j] = false; 
    block t,a;
    a.x=src[0];
    a.y=src[1];
    a.dis=0;
    q.push(a);
    //cout<<src[0]<<src[1]<<" ";
    // t =q.front();  
     //cout<<t.x<<" "<<a.y<<" ";
    visited[src[0]][src[1]]=true;
    
    while(!q.empty()){
        t =q.front();  
        //cout<<t.x<<" "     ;
        q.pop();       
        if(t.x==dest[0] && t.y==dest[1])
        minn=min(minn,t.dis);
        for(int k=0;k<8;k++){  
            //cout<<"t.x is"<<t.x<<" ";
            int p=t.x+row[k];
            //cout<<"p is"<<p<<" ";
            int l=t.y+col[k];
            if(safe(p,l,n) && !visited[p][l]){
                visited[p][l]=true;
                int r=t.dis+1;
                block s;
                s.x=p;
                s.y=l;
                s.dis=r;
                q.push(s);
            }
        }
        
    }
    return minn;
}
int main() 
{ 
    int N = 6; 
    // int knightPos[] = { 1, 1 }; 
    // int targetPos[] = { 6, 6 }; 
    // int knightPos[] = { 3, 4 }; 
    // int targetPos[] = { 6, 1 };
    int knightPos[] = { 4, 5 }; 
    int targetPos[] = { 1, 1 }; 
    cout << minStepToReachTarget(knightPos, targetPos, N); 
    return 0; 
} 