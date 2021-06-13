#include<string.h>
#include <cmath>
#include<cstdio>
#include<vector>
#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;
void solve(vector<int>& P, int n)
{
 
    // New array to convert
    // to 1-based indexing
    vector<int> arr;
 
    arr.push_back(0);
 
    for (auto x : P)
        arr.push_back(x);
 
    // Keeps count of swaps
    int cnt = 0;
 
    for (int i = 1; i < n; i++) {
 
        // Check if it is an 'X' position
        if (arr[i] == i) {
            swap(arr[i], arr[i + 1]);
            cnt++;
        }
    }
 
    // Corner Case
    if (arr[n] == n) {
 
        swap(arr[n - 1], arr[n]);
        cnt++;
    }
 
    // Print the minimum swaps
    cout << cnt << endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> P;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        P.push_back(x);
    }
    solve(P,n);
}