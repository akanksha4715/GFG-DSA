#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    cin>>vec[i];
    sort(vec.begin(),vec.end(),greater<int>());
    int k=0,i=1;
    int maxx=vec[0];
    cout<<"==============";
    for(i=1;i<=maxx;i++){
        k++;
        if(i+vec[k]<maxx)
        maxx=i+vec[k];
    }
    cout<<endl<<i;
    return 0;
}