#include<iostream>
#include<algorithm>
using namespace std;
bool mycmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}
int activitySelection(int start[],int end[],int n){
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        p[i].first=start[i];
        p[i].second=end[i];
    }
    sort(p,p+n,mycmp);
    int prev=0;
    int res=1;
    //int curr=1;
    for(int i=1;i<n;i++){
        cout<<p[prev].second<<" ";
        if(p[prev].second<=p[i].first){
            prev=i;
            res++;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int start[n],end[n];
    for(int i=0;i<n;i++)
    cin>>start[i];
    for(int i=0;i<n;i++)
    cin>>end[i];
    cout<<activitySelection(start,end,n);
    return 0;
}