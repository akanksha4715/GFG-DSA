#include<iostream>
#include<vector>
using namespace std;
// if(i==j)
//     return arr[i];
//     if(i+1==j)
//     return max(arr[i],arr[j]);

//     return max(arr[i]+min(sol(arr,i+2,j),sol(arr,i+1,j-1)),
//                 arr[j]+min(sol(arr,i+1,j-1),sol(arr,i,j-2)));
int sol(vector<int> arr,int n){
    int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=arr[i];       
    }
    for(int i=0;i<n-1;i++)
    dp[i][i+1]=max(arr[i],arr[i+1]);
    
    for(int gap=2;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j=gap+i;
            dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
                        arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}
 bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int asum=sol(nums,n);
        for(int i=0;i<n;i++)
            sum=sum+nums[i];
        int bsum=sum-asum;
        return asum>=bsum?true:false;
    }
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
    nums.push_back(x);
    }
    cout<<PredictTheWinner(nums)<<endl;
    return 0;
}