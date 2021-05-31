#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if(n==1)
            ans.push_back({1});
        else if(n==2){
            ans.push_back({1});
            ans.push_back({1,1});
        }            
        else{
            ans.push_back({1});
            ans.push_back({1,1});
            for(int i=2;i<n;i++){
                 vector<int> v;
                for(int j=0;j<=i;j++){
                   
                    if(j==0 || j==i){
                        v.push_back(1);
                    }
                    else{
                        int sum=ans[i-1][j-1]+ans[i-1][j];
                        v.push_back(sum);
                    }
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};