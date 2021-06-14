#include<string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;

unordered_set<string> printAllKLengthRec(string str, string prefix,int n, int k,unordered_set<string> sett)
                                    
{
     
    if (k == 0)
    {   //cout<<prefix<<endl;
        sort(prefix.begin(), prefix.end());
        sett.insert(prefix);
        return sett;
    }
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + str[i];
        sett=printAllKLengthRec(str, newPrefix, n, k - 1,sett);
    }
    return sett;
 
}
 

void query1(string s,int l,int r,int k){
    unordered_set<string> sett;
    string str=s.substr(l-1,r-l+1);
    int len=str.length();
    sett=printAllKLengthRec(str, "", len, k,sett);
    cout<<sett.size()<<endl;
    
}
string query2(string s,int p,char c){
    s[p-1]=c;
    return s;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int l,r,k;
    int p;
    char c;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(x==1){
            
            cin>>l>>r>>k;
            query1(s,l,r,k);
        }
        else{
            
            cin>>p;
            cin>>c;
           s= query2(s,p,c);
        }
        
    }

    return 0;
}
/*
8 4
elemente
1 1 3 2
2 3 b
1 1 3 2
1 1 8 9
*/