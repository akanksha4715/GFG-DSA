#include<bits/stdc++.h>
using namespace std;


void powerr(string s,vector<string> &v,int index=0,string curr =""){
    int n = s.length();
    if(index==n){
        v.push_back(curr);
        return;
    }
    powerr(s,v,index+1,curr);
    powerr(s,v,index+1,curr+s[index]);
    
}
vector<string> powerset(string &s){
vector<string> an ; powerr(s,an);
sort(an.begin(),an.end());
return an;
}
int main(){
    string s;
    cin>>s;
    vector<string> ans = powerset(s);
    for(auto x:ans){
        cout<<x<<" ";
    }
}
