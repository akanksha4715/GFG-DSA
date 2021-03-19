#include<vector>
#include<iostream>
#include<queue>
using namespace std;
bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len=rooms.size();
        cout<<len;
        queue<int> q;
        q.push(0);
        int vis[len];

        vis[0]=true;
        for(int i=1;i<len;i++)
            vis[i]=false;

        while(q.empty()==false){
            int u =q.front();
            q.pop();
            for(int x: rooms[u]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        for(int i=1;i<len;i++){
            if(vis[i]==false)
                return false;
        }
        return true;
        
}
