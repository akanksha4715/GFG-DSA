#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int> mp;
        pair<string,int> pr = make_pair(arr[0],0);
        vector<string> vec;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();++itr){
            if(itr->second > pr.second){
                pr= make_pair(itr->first,itr->second);
            }
            else if(itr->second == pr.second && itr->first < pr.first){
                pr= make_pair(itr->first,itr->second);
            }
        }
        string x=to_string(pr.second);
        vec.push_back(pr.first);
        vec.push_back(x);
        return vec;
        
        
        
    }