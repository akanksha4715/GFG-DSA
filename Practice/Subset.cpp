#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> vec,int n){
    int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            vector<int> arr;
            arr.assign(vec.begin()+i, vec.end()-n+j+1);
            
            int sz=arr.size();
            unordered_set<int> sett;
            int flag=1;
            for(int k=0;k<sz;k++){
                for(int l=0;l<10;l++){
                    int temp=arr[k]/prime[l];
                    if(temp%prime[l]==0)
                    break;
                    else if(arr[k]%prime[l]==0){
                        if(sett.find(prime[l])==sett.end()){
                            sett.insert(prime[l]);
                        }
                        else{
                            break;
                            flag=0;
                        }
                    }
                }
            }
            sett.clear();
            if(flag==1)
            count++;
        }
    }
    return count;
}
int main(){
    int n=4;
    vector<int> arr={4,3,2,15};
    cout<<solve(arr,n);
}