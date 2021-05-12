#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr;
        int n=nums.size();
        if(n<3)
            return arr;
        sort(nums.begin(),nums.end());
        set<vector<int>> sett;
        for(int i=0;i<n;i++){
            int target= -1 * nums[i];
            int low=i+1;
            int high =n-1;
            
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==target){
                vector<int> vec={nums[i],nums[low],nums[high]};
                sett.insert(vec);
                low++;
                high--;
            }
            else if(sum<target){
                if(nums[low]<nums[high])
                    low++;
                else
                    high--;
            }
            else{
                if(nums[low]<nums[high])
                    high--;
                else
                    low++;
            }
            
        }//end while
        } //end for
        for(vector<int> x: sett){
            arr.push_back(x);
        }
        return arr;
    }
int main(){
    vector<int> nums ={3,2,4};
    int n=6;
    vector<vector<int>> v=threeSum(nums);
    for(int i=0;i<v.size();i++)
   // cout<<v[i]<<" ";
    return 0;
}