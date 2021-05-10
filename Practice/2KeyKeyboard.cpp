#include<bits/stdc++.h>
using namespace std;
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
        return 1+fn(1,1,n);
    }
//Optimized
