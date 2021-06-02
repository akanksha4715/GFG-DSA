#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int x;
    cin>>x;
    string str;
    while(x!=0){
        str.append(to_string(x%2));
        x=x/2;
    }
    reverse(str.begin(),str.end());
    cout<<str;
}