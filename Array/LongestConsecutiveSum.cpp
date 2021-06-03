#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sett;
        int n=nums.size();
        if(n==0)
            return 0;
        int curlen=1,maxlen=1;
        
        for(int i=0;i<n;i++){
            sett.insert(nums[i]);
        }
        
        for(int i=0;i<n;i++){          
            int curr=nums[i];
            if(sett.find(curr-1)==sett.end()){
            curlen=1;
                
            while(sett.find(++curr)!=sett.end()){
                curlen++;             
            }
                
                maxlen=max(curlen,maxlen);
            }
            
        }
        return maxlen;
    }
};