#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct bpairs
{
    int first;
    int sec;
    bpairs(){}
};
bool mycmp(bpairs a,bpairs b){
    if(a.first!=b.first)
    return a.first<b.first;
    else
    {
       return a.sec<b.sec;
    }   
}
int findceil(vector<int> tail,int key,int r){
    int l=0;
    while(l<r){
        int m=l+(r-l)/2;
        if(tail[m]>=key)
        r=m;
        else
        {
            l=m+1;
        }   
    }
    return r;
}
int lis(bpairs pairs[],int n){
    
    vector<int> tail;
    tail.push_back(pairs[0].sec);
    int len=1;
    
    for(int i=1;i<n;i++){
        if(pairs[i].sec>tail[len-1]){
            tail.push_back(pairs[i].sec);
            len++;
        }
        else{
            int id=findceil(tail,pairs[i].sec,len-1);
            tail[id]=pairs[i].sec;
        }
    }
    return len;
}
int main(){
    int n;cin>>n;
    bpairs pairs[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pairs[i].first=a;
        pairs[i].sec=b;
    }
    sort(pairs,pairs+n,mycmp);
    cout<< lis(pairs,n);
    return 0;
}
/*sample input
4
6 2
4 3
2 6
1 5*/
