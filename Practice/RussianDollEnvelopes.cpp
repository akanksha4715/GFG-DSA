#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++){
            pr.push_back(make_pair(envelopes[i][0],envelopes[i][1]) );
        }
        sort(pr.begin(),pr.end());
        int i=0,j=1,count=1;
        while(j<n){
            if(pr[i].first<pr[j].first && pr[i].second<pr[j].second){
                count++;
                i++;
                j++;
            }
            if(pr[i].first==pr[j].first && pr[i].second==pr[j].second){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
int main(){
    vector<vector<int>> vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<2;j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        vec.push_back(v);
    }
    cout<<maxEnvelopes(vec);
}