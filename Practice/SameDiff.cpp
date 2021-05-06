#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
    t--;
    int n,j;
    long long count=0;
    cin>>n;
    vector<int> vec;
    map<int,int> sett;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        j=x-i;
        count+=sett[j];
        sett[j]++;
    }
    cout<<count<<endl;
    }
    return 0;
}