//
//  main.cpp
//  test
//
//  Created by Amitabh Sharma on 08/12/20.
//


#include <iostream>
#include <vector>

using namespace std;

bool dfs(int i, int j, vector<vector<int> > &M, int N)
{
    
    if (M[i][j] == 2)
        return true;
    if(M[i][j]!=3)
        return false;
    M[i][j]=0;

    if (i>0)
        if (dfs(i - 1, j, M, N))
            return true;

    if (j>0)
        if (dfs(i, j - 1, M, N))
            return true;

    if (j<N-1)
        if (dfs(i, j + 1, M, N))
            return true;

    if (i<N-1)
        if (dfs(i + 1, j, M, N))
            return true;
    return false;
}

bool is_possible(vector<vector<int> > &M, int N)
{

    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (M[i][j]==1)
                break;
        }
        if (M[i][j]==1)
            break;
    }
        if (i>0)
            if (dfs(i - 1, j, M, N))
                return true;

        if (j>0)
            if (dfs(i, j - 1, M, N))
                return true;

        if (j<N-1)
            if (dfs(i, j + 1, M, N))
                return true;

        if (i<N-1)
            if (dfs(i + 1, j, M, N))
                return true;

        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > a(1000, vector<int>(1000, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        cout << is_possible(a, n) << endl;
    }
    return 0;
}