#include<iostream>
#include<vector>
using namespace std;
vector<int> coins;
int fn(int target,int i,int n){
    
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
        int ans;
        if(target-coins[i]==0)
        ans=1;
        else
        ans=fn(target-coins[i],i,n);
        
        if(ans!=-1)
        count+=ans;
    }
    cout<<endl<<count;
    return 0;
}