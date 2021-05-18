#include<iostream>
#include<vector>
using namespace std;
vector<int> coins;
int fn(int target,int i,int n){
    int count=0;
    if(target==0)
    return 0;
    else if(coins[i]-target==0)
    return 1;
    else if(target-coins[i]<0)
    return -1;
    else{
        for(int j=0;j<n;j++){
            int ans=fn(target-coins[j],j,n);
            cout<<ans<<" ";
            if(ans!=-1)
            count+=ans;
        }
    }
    return count;
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
    coins=vec;
    for(int i=0;i<n;i++){
        int ans=fn(target-coins[i],i,n);
        
        if(ans!=-1)
        count+=ans;
    }
    //cout<<count;
    return 0;
}