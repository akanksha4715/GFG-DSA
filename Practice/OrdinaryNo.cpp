#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        int n,ans;
        cin>>n;
        if(n<10)
        cout<<n<<endl;
        else
        {
            int q=n/10;
            ans=9+q-1;
            int num=q*10+q;
            n>=num ? ans+1 : ans;
            cout<<ans<<endl;
        }
    }
    return 0;
}