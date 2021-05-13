#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
vector<string> possiblenumbers(int n,int a[]){

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    vector<string> poss = possiblenumbers(n,a);
    for(auto x:poss)
    cout<<x<<" ";
    return 0;
}