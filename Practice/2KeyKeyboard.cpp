#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
//Brute force
int fn(int i,int j,int n){
        if(n==1)
            return -1;
        if(n==j)
            return 0;
        if(j>n)
            return 1001;
        return min(1+fn(i,j+i,n),2+fn(j,j+j,n));
    }
    int minSteps(int n) {
        // unordered_map<string,int> mp;
        return 1+fn(1,1,n);
    }
//Optimized 
int Fn(int i,int j,int n){
   string c=to_string(i)+" "+to_string(j);
   if(n==1)
        mp[c]=-1;
    if(n==j)
        mp[c]=0;
    if(j>n)
        mp[c]=1001;
    if(mp.find(c)!=mp.end())
       return mp[c];
    mp[c]=min(1+fn(i,j+i,n),2+fn(j,j+j,n)); 
    return mp[c];
}
int minSteps(int n) {
        return 1+Fn(1,1,n);
    }
    // weird thing is optimized version is actually not optimized. Strangely it is taking more time than brute force