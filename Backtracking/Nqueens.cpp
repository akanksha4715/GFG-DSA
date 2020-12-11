#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isSafe(int row,int col,vector<vector<int>> board,int n){
    for(int i=0;i<col;i++){
        if(board[row][i])
        return false;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j])
        return false;
    }
    for(int i=row+1,j=col-1;i<n && j>=0;i++,j--){
        
        if(board[i][j])
        return false;
    }
    return true;
}
bool queens(int col,vector<vector<int>> &board,int n){
    if(col==n) return true;;
    for(int i=0;i<n;i++){
        if(isSafe(i,col,board,n)){
            board[i][col]=1;
            if(queens(col+1,board,n))
            return true;
            board[i][col]=0;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> > board;
    for(int i=0;i<n;i++){
        vector<int> v1;
        for(int j=0;j<n;j++)
        v1.push_back(0);
        board.push_back(v1);
    }
    if(!queens(0,board,n))
    cout<<"No sol possible";
    else{
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";    
        }       
    }
    return 0;
}