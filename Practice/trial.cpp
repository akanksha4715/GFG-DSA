#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans ;
        int low=0;
        int high =nums.size()-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==target){
                ans.push_back(low);
                ans.push_back(high);
                break;
            }
            if(sum<target){
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
            
        }
        return ans;
}
int main(){
    vector<int> v1={2,5,8};
    vector<int> v2={2,5,8};
    cout<<(v1==v2);
    return 0;
}