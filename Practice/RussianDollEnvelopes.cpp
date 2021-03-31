#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool mycmp(pair<int,int> a,pair<int,int> b){
    if(a.first<b.first)
    return true;
    else if(a.first==b.first)
    return a.second<b.second;
    return false;
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        int count=1;
        int arr[n];
        arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i]=1;
            for(int j=0;j<i;j++){
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1]){
                    arr[i]=max(arr[i],arr[j]+1);
                }
            }
            count=max(arr[i],count);
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
    
    
    cout<<endl;
    cout<<maxEnvelopes(vec);
}