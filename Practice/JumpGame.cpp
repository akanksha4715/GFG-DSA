#include<bits/stdc++.h>
using namespace std;
//check if reaching last index is feasible or not by jumping
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n,0);
        //memset(vis,0,sizeof(vis));
        vis[0]=1;
        for(int i=0;i<n;i++){
            cout<<vis[i]<<" ";
            if(vis[n-1]==1)
                return true;
            if(vis[i]==1)
            {
            int x=nums[i];
            if(i+x<n)
            fill(vis.begin()+i,vis.begin()+i+x+1,1);
            else
            fill(vis.begin()+i,vis.end(),1);          
            }
        }
        return false;
    }
};
class solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0,i;
        for( i=0;i<n && i<=reach;i++){
             reach=max(i+nums[i],reach);
           // cout<<reach<<" ";
        }
        cout<<i;
        return i==n;
    }
};