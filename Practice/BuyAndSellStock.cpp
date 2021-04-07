#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=INT_MAX;
        int maxp=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<minn)
            minn=prices[i];
            else if(prices[i]-minn>maxp)
                maxp=prices[i]-minn;
        }
        return maxp;
    }
   
};
