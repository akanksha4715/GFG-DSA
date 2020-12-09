#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++


// M : input matrix
// N : size of the matrix
int issafe(vector <vector<int>> &M,int N,int i,int j,vector<vector<bool>> &visited){
    if(i>=0 && j>=0 && i<N && j<N && !visited[i][j]){
        if(M[i][j]==2)
        return 2;
        else if(M[i][j]==3)
        return 3;
        else return 0;
    }
    else return 0;
}
bool DFS(vector <vector<int>> &M,int N,int si,int sj,vector<vector<bool>> &visited){
    int row[] ={0,-1,0,1};
    int col[]={-1,0,1,0};
    bool ans=false;
    if(!visited[si][sj]){
        visited[si][sj]=true;
        for(int k=0;k<4;k++){
            if(issafe(M,N,si+row[k],sj+col[k],visited)==2){
                ans= true;
            }
            else if(issafe(M,N,si+row[k],sj+col[k],visited)==3){
                if(DFS(M,N,si+row[k],sj+col[k],visited))
                ans=true;
            }
        }
    }
     return ans;
}
bool is_possible(vector <vector <int>> &M, int N) {
    int si,sj;
    vector<vector<bool>> visited;
    for (int i = 0; i < N; i++) { 
        vector<bool> v2; 
        for (int j = 0; j < N; j++) { 
            
            v2.push_back(0);     
        } 
        visited.push_back(v2); 
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(M[i][j]==1)
            {
                si=i;
                sj=j;
                break;
            }
        }
    }
    if(DFS(M,N,si,sj,visited))
    return true;
    else 
    return false;
}

