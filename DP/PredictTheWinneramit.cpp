#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	pair<int,int>score;
	unordered_map<string,int>map;
	int findMaxVal(vector<int>& nums,bool pfirst,int start,int end){
		string hval;
		for(int i=start;i<end;i++)
		{
			hval+=to_string(nums[i]);
			hval+=',';
		}
		if(map.find(hval)!=map.end())
		{
			return map[hval];
		}
		if(start+1==end)
		{
			if(pfirst)
			{
				score.first+=max(nums[start],nums[end]);
				score.second+=min(nums[start],nums[end]);
			}
			else
			{
				score.second+=max(nums[start],nums[end]);
				score.first+=min(nums[start],nums[end]);
			}
			return max(nums[start],nums[end]);
		}
		int fval=findMaxVal(nums,!pfirst,start+1,end);
		int eval=findMaxVal(nums,!pfirst,start,end-1);
		int val;
		if(eval==fval)
			val=max(nums[start],nums[end]);
		else
			val=fval<eval?nums[start]:nums[end];
		if(pfirst)
			score.first+=val;
		else
			score.second+=val;
		map[hval]=val;
		cout<<val<<endl;
		return val;

	}

    bool PredictTheWinner(vector<int>& nums) {
        findMaxVal(nums,1,0,nums.size()-1);
        return score.first>=score.second?true:false;
    }
};

int main(){

	int n;
	cin>>n;
	vector<int>nums(n);

	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	Solution s;
	if(s.PredictTheWinner(nums))
	{
		cout<<"true";
	}
	else
		cout<<"false";
	return 0;
}