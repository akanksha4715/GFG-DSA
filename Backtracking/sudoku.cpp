#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool isSafe(int row,int col,int num,int n,vector<vector<int>> sudo){
    int sq=(int) sqrt(n);
    for(int i=0;i<n;i++){
        if(sudo[i][col]==num || sudo[row][i]==num)
        return false;
    }
    int rstrt=row - row%sq;
    int cstrt = col - col%sq;
    for(int i=rstrt;i<rstrt+sq;i++){
        for(int j=cstrt;j<cstrt+sq;j++){
            if(sudo[i][j]==num)
            return false;
        }
    }
    return true;
}
bool sudok(int n,vector<vector<int>> &sudo){
    int i,j,row=-1,col=-1;
    for( i=0;i<n;i++){
        for( j=0;j<n;j++){
            if(sudo[i][j]==0){
                row=i;
                col=j;
                break;
            }
        }
        if(sudo[i][j]==0)
        break;
    }
    if(row!=-1 || col!=-1){
    for(int p=1;p<=n;p++){
        if(isSafe(row,col,p,n,sudo)){
            sudo[row][col]=p;
            if(sudok(n,sudo))
            return true;
            sudo[row][col]=0;
        }
    }
    }
    return false;
}
void print(vector<vector<int>> &sudo,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sudo[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int n,u;
    cout<<"Enter size of board ";
    cin>>n;
    vector<vector<int>> sudoku;
    cout<<"Enter board"<<endl;
    for (int i = 0; i < n; i++)
    {   vector<int>v1;
        for(int j=0;j<n;j++){
        cin>>u;
        v1.push_back(u);
        }
        sudoku.push_back(v1);
    }
    sudok(n,sudoku);
    print(sudoku,n);
    return 0;
}