#include<iostream>
#include<unordered_set>
using namespace std;
int inter(int a[],int b[],int n,int m){
    unordered_set<int> sett;
    int count=0;
    for(int i=0;i<n;i++){
        sett.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        if(sett.find(b[i])!=sett.end())
        {
            count++;
            sett.erase(b[i]);
        }
    }
    return count;
}
int main(){
    int m,n;
    cin>>m>>n;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];
    cout<<inter(a,b,n,m);
    return 0;
}