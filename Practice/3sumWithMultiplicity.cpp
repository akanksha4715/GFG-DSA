//find all pairs of 3 nums i<j<k to add up to target
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int mod=1e9 +7;
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9 +7;
        int n=arr.size();
        unordered_map<int,int> mp;
        int res;
        for(int i=0;i<n;i++){
            res=mp[target-arr[i]]%mod;
            for(int j=0;j<i;j++)
            mp[arr[i]+arr[j]]++;
        }
        return res;
    }
};
