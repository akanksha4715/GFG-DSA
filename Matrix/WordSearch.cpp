#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int x,int y,char w,vector<vector<char>> &board,vector<vector<bool>> &visited){
        int m=board.size();
        int n=board[0].size();
        return x>=0 && x<m && y>=0 && y<n && board[x][y]==w && !visited[x][y];
    }
    bool search(vector<vector<char>> &board,vector<vector<bool>> &visited,string w,int si,int sj,int index){
        if(index==w.length())
            return true;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int x=si+row[i];
            int y=sj+col[i];
            if(isSafe(x,y,w[index],board,visited)){
                visited[x][y]=1;
                if(search(board,visited,w,x,y,index+1))
                    return true;
                else
                    visited[x][y]=0;
            }
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                visited[i].push_back(0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                  visited[i][j]=1;
                    if(search(board,visited,word,i,j,1))
                        return true;
                    else
                        visited[i][j]=0;
                }
            }
        }
        return false;
    }
};