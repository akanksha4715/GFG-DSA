#include<bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n=10;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        bool there=false;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                //cout<<arr[j];
                there=true;
                break;
            }
        }
        if(!there)
            cout<<arr[i]<<" ";
    }
    return 0;
}