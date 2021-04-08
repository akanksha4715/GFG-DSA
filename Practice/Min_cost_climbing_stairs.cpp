#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   // vector<int> arr;
    int func(vector<int> arr,vector<int> &aux,int start,int i,int j){
        if(aux[start]!=-1)
            return aux[start];
        else{
            if(j-i<=0){
                aux[start]=arr[start];
            }
            else if(j-i==1){
                aux[start]=arr[start]+min(arr[i],arr[j]);
            }
            else{
                aux[start]=arr[start]+min(func(arr,aux,i,i+1,j),func(arr,aux,i+1,i+2,j));
            }
            return aux[start];
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //arr=cost;
     int n=cost.size();
        vector<int> aux(n,-1);
        //memset(aux,-1,sizeof(cost));
        return min(func(cost,aux,0,1,n-1),func(cost,aux,1,2,n-1));
    }
};