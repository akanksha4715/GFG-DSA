#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k=0;
    cin>>n;
    float x;
    vector<float> wt(n);
    vector<float> ht(n);
    vector<float> ans;
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++){
        cin>>x;
        x=x/1000;
        x*=x*100;
        //cout<<x;
        ht[i]=x;
    }
    for(int i=0;i<n;i++){
        if(wt[i]/ht[i]< 18.5 || wt[i]/ht[i]>24.9)
        {
            ans.push_back(wt[i]/ht[i]);
            //cout<<wt[i]<<" "<<ht[i]<<" "<<ans[k]<<endl;
            k++;
        }
    }
    k=ans.size();
    sort(ans.begin(),ans.end());
    //cout<<ans[0];
    for(int i=0;i<k;i++){
        cout<<fixed<< setprecision(4) << ans[i] <<endl;
    }
    return 0;
}
/*
4
56
98
78
75
154 
172
198
165
*/