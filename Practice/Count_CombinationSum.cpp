#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int>> res;
set<vector<int>> sett;
//2 3 6 7 
//7
void solve(vector<int>& candidates, int target,vector<int> &ans){
    if(target==0){
        vector<int> temp=ans;
        sort(temp.begin(),temp.end());
        if(sett.find(temp)==sett.end()){
            res.push_back(temp);
            sett.insert(temp);
        }
        
    }
    else{

        for(int x:candidates){
            if(target-x>=0){
            ans.push_back(x);
            solve(candidates,target-x,ans);
            ans.pop_back();
            }
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<int> answer;
    sort(candidates.begin(),candidates.end());
    solve(candidates,target,answer);
    return res;
}
int main(){
    int n=4,count=0;
    int target=7;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<vector<int>> res=combinationSum(vec,target);
    cout<<res.size();
    return 0;
}