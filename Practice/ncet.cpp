#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> goals(int X, int Y, int Z){
        int c1 = 0, c2 = 0;
        while(Z > 1){
            if(X%Z == 0){
                c1++;
                X--;
            }
            if(Y%Z == 0){
                c2++;
                Y--;
            }
            else
                Z--;
        }
        vector<int> val;
        val.push_back(c1);
        val.push_back(c2);
        return val;
    }
int main(){
    //int t;
    //cin>>t;
    //while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        vector<int> ans;
        ans=goals(x,y,z);
        int n=ans.size();
        for(int i=0;i<n-1;i++)
        cout<<ans[i]<<" ";

        cout<<ans[n-1];
    //}
}