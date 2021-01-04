#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int n,int w){
    if(n==0 || w==0) return 0;
    if(wt[n-1]>w)
    return knapsack(wt,val,n-1,w);
    else
    {
        return max(knapsack(wt,val,n-1,w),
        val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]));
    }   
}
int main(){
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    for(int i=0;i<n;i++)
    cin>>val[i];
    cout<<knapsack(wt,val,n,w);
    return 0;
}