#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int end=0;
        for(int i=1;i<n;i++){
            if(nums[end]!=nums[i]){
                end++;
                swap(nums[end],nums[i]);
            }               
            }
        return end+1;
    }
};