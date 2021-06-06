#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> aux;
        int n=nums.size();
        k=(k%n)%n;
        aux.assign(nums.begin(),nums.begin()+n-k);
        int len=aux.size();
        int x=0,y=0;
        for(int i=n-k;i<n;i++)
        {
            nums[x]=nums[i];
            x++;
        }
        while(len--){
            nums[x]=aux[y];
            x++;
            y++;
        }
    }
};