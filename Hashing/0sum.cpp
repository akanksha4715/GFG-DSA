#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int sumZero(int v[],int n){
    unordered_set<int> s;
    int sum=0,count=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        if(s.find(sum)!=s.end())
        count++;
        if(sum==0)
        count++; 
        s.insert(sum);
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<sumZero(v,n);
    return 0;
}