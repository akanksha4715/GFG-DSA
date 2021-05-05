#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    vector<string> vec;
    for(int i=0;i<=n;i++)
    {
        getline(cin,s);
        vec.push_back(s);
    }
    vec.erase(vec.begin());
    for(int i=0;i<n;i++)
    cout<<vec[i]<<" ";
    //cout<<endl<<vec[1];
    return 0;
}