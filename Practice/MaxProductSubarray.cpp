#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx=INT16_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int pro=1;
            //maxx=pro;
            for(int j=i;j<n;j++){
                pro=pro*nums[j];
                maxx=max(pro,maxx);
            }
        }
        return maxx;
    }
};