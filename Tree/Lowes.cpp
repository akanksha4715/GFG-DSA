#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a,vector<int> b)
{
    return a[0]<b[0];
}
int fn(int n,int b,vector<vector<int>> vec){
    int len=vec.size();
    int origin;int count=0,loop=0;int i;
    for(i=0;i<len;i++){
          loop++;    
        if(vec[i][0]==b)
        {   
            if(loop>1)
            count++;
            vec[i][0]=n+1;
            origin=vec[i][1];
            count=count+fn(n,origin,vec);
        }
        vec[i][0]=b;
    }
    return count+1;

}
int countPatterns(int n,int b,vector<vector<int>> vec){
    sort(vec.begin(),vec.end(),cmp);
    
    return fn(n,b,vec)+1;
}
int main(){
    int n=6;
    int b=1;
    vector<vector<int>> vec={
        //{1,2},{2,3},{2,4},{4,5},{4,6}
        {1,2},{1,3}
    };
    cout<<countPatterns(n,b,vec);
}