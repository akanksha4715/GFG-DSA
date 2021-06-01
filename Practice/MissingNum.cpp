#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),sum=0;
        int expectedsum=n*(n+1)/2;
        for(int x:nums)
            sum+=x;
        return expectedsum-sum;
    }
};