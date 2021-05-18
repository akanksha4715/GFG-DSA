#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        int dp[n][sum+1];
        for(int i=0;i<n;i++)
            dp[i][0]=0;
        
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<n;j++){
                if(i<coins[j])
                    dp[i][j]=dp[i-1][j];
                else
                    
                dp[i][j]=min(dp[i-coins[j]][j]+1,dp[i-1][j]);
            }
        }
        int ans= dp[n-1][sum];
        if(ans==INT16_MAX)
            return -1;
        else 
            return ans;
    }
};
int main(){
    vector<int> v1={2,5,8};
    vector<int> v2={2,5,8};
    cout<<(v1==v2);
    return 0;
}