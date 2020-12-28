#include<iostream>
#include<cmath>
using namespace std;
int maxx(int head[],int tail[],int n){
    int res=head[0]+tail[0]-1;
    for(int i=1;i<n;i++){
        res=max(res,head[i]+tail[i]-1);
    }
    return res;
}
int longestbitonic(int n,int arr[]){
    int head[n],tail[n];
    head[0]=1;
    tail[n-1]=1;
    for(int i=1;i<n;i++){
        head[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
            head[i]=max(head[i],head[j]+1);
        }
    }
    cout<<endl;
    for(int i=n-2;i>=0;i--){
        tail[i]=1;
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j])
            tail[i]=max(tail[i],tail[j]+1);
        }       
    }
    return maxx(head,tail,n);
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cout<<longestbitonic(n,a);
return 0;
}