#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(); int n=matrix[0].size();
        vector<int> ans;
        int topleft=0,topright=n-1,bottomleft=m-1,bottomright=n-1;
        while(topleft<bottomleft && topright<bottomright){
            for(int i=topleft;i<=topright;i++){
                ans.push_back(matrix[topleft][i]);
            }
            topleft++;topright++;
            for(int i=topright;i<=bottomright;i++){
                ans.push_back(matrix[i][topright]);
            }
            topright--;bottomright--;
            for(int i=bottomright;i<=bottomleft;i++){
                ans.push_back(1);
            }
        }
        
    }
};