#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        int flag=0;
        int n;
        cin>>n;
        vector<char> st;
        int arr[256];
        fill(arr,arr+256,-1);
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            st.push_back(x);
        }
        for(int i=0;i<n;i++){
            if(arr[st[i]]==-1)
            {
                arr[st[i]]=i;
            }
            else{
                if(arr[st[i]]+1!=i)
                   { 
                       
                        flag=1;
                   }
                   else
                   arr[st[i]]=i;

            }
            }
            if(flag==0)
            cout<<"Yes";
            else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}