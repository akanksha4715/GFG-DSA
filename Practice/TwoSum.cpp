#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int,int> &a,pair<int,int> &b){
        return (a.first < b.first);
}

vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++){
            pr.push_back(make_pair(nums[i],i));
        }
        sort(pr.begin(),pr.end(),mycmp);
        vector<int>ans ;
        int low=0;
        int high =n-1;
        while(low<high){
            int sum=pr[low].first + pr[high].first;
            if(sum==target){
                ans.push_back(pr[low].second);
                ans.push_back(pr[high].second);
                break;
            }
            if(sum<target){
                if(pr[low].first<pr[high].first)
                    low++;
                else
                    high--;
            }
            else{
                if(pr[low].first<pr[high].first)
                    high--;
                else
                    low++;
            }
            
        }
        return ans;
    }
int main(){
    vector<int> nums ={3,2,4};
    int n=6;
    vector<int> v=twoSum(nums,n);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;
}