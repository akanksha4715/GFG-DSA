#include<bits/stdc++.h>
using namespace std;
class Solution {
public:vector<vector<int>> ans;
    void permutation(vector<int> &nums,int l,int r){
        if(l==r)
            ans.push_back(nums);
        else{
            for(int i=l;i<r;i++){
                swap(nums[i],nums[l]);
                permutation(nums,l+1,r);
                swap(nums[i],nums[l]);
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();       
        permutation(nums,0,n);
        return ans;
    }
};