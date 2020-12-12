#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row,int col,int n,vector<vector<int>> sudo){

}
void sudok(int n,vector<vector<int>> sudo){

}
void print(vector<vector<int> sudo){

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
    print(sudoku);
    return 0;
}