#include<iostream>
#include<unordered_set>
using namespace std;
int inter(int a[],int b[],int n,int m){
    unordered_set<int> sett;
    
    for(int i=0;i<n;i++)
    {
        sett.insert(a[i]);
        
    }
    // for(int x:sett)
    // cout<<x;
    for(int i=0;i<m;i++)
    {
        if(sett.find(b[i])==sett.end())
        {
            sett.insert(b[i]);
            
        }
    }
    
    return sett.size();
}
int main(){
    int m,n;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];
    cout<<inter(a,b,n,m);
    return 0;
}