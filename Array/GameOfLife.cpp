#include<bits/stdc++.h>
using namespace std;
class Solution {
public:int rows,cols;
    bool isSafe(int i,int j){
        return (i>=0 && i<rows && j>=0 && j<cols);
    }
    int count(vector<vector<int>> board,int x,int y){
        int row[]={0,-1,-1,-1,0,1,1,1};
        int col[]={-1,-1,0,1,1,1,0,-1};
        int sum=0;
        for(int k=0;k<8;k++){
        if(isSafe(x+row[k],y+col[k])){
            if(board[x+row[k]][y+col[k]])
                sum++;
        }
        }
        return sum;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size(); 
        rows=n;
        cols=m;
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num=count(board,i,j);
                //cout<<num<<" ";
                if(board[i][j]==0 && num==3)
                    ans[i].push_back(1);
                else if(board[i][j]==0 && num!=3)
                    ans[i].push_back(0);
                else if(board[i][j]==1 && num<2)
                    ans[i].push_back(0);
                else if(board[i][j]==1 && num>3)
                    ans[i].push_back(0);
                else 
                    ans[i].push_back(1);
            }
            //cout<<endl;
        }
        board=ans;
        
    }
};