#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    string word="xxyzyzhb";
    string s2="xyz";



    int len=s2.length();
    int end=word.find(s2);
    while(end!=-1){
    word.replace(end,len,"");
    end=word.find(s2);
    }
    cout<<word.length();
    return 0;
}