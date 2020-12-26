#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int getceilid(vector<int> tail,int r,int key){
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
int longestSubsequence(int n, int a[])
{
 vector<int> tail;
 int len=1;
 tail.push_back(a[0]);
 for(int i=1;i<n;i++){
     if(a[i]>tail[len-1]){
         tail.push_back(a[i]);
         len++;
     }
     else
     {
         int id=getceilid(tail,len,a[i]);
         tail[id]=a[i];
     }
     
 }
 return len;
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cout<<longestSubsequence(n,a);
return 0;
}