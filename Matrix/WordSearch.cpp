#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int x,int y,char w,vector<vector<char>> &board){
        int m=board.size();
        int n=board[0].size();
        return x>=0 && x<m && y>=0 && y<n && board[x][y]==w;
    }
    bool search(vector<vector<char>> &board,string w,int si,int sj,int index){
        if(index==w.length())
            return true;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int x=si+row[i];
            int y=sj+col[i];
            if(isSafe(x,y,w[index],board)){
                board[x][y]='*';
                if(search(board,w,x,y,index+1))
                    return true;
                else
                    board[x][y]=w[index];
            }
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                  board[i][j]='*';
                    if(search(board,word,i,j,1))
                        return true;
                    else
                        board[i][j]=word[0];
                }
            }
        }
        return false;
    }
};