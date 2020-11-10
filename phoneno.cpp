#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
vector<string> possiblenumbers(int n,int a[]){
vector<string> poss;
string str1,str2,str3;
switch(a[0]){
    case 1:str1="";break;
    case 2:str1="abc";break;
    case 3: str1="def";break;
    case 4: str1="ghi";break;
    case 5: str1="jkl";break;
    case 6:str1="mno"; break;
    case 7:str1="pqrs";break;
    case 8:str1="tuv";break;
    case 9:str1="wxyz";break;
    default:str1="";
}
switch(a[1]){
    case 1:str2="";break;
    case 2:str2="abc";break;
    case 3: str2="def";break;
    case 4: str2="ghi";break;
    case 5: str2="jkl";break;
    case 6:str2="mno"; break;
    case 7:str2="pqrs";break;
    case 8:str2="tuv";break;
    case 9:str2="wxyz";break;
    default:str2="";
}
switch(a[2]){
    case 1:str3="";break;
    case 2:str3="abc";break;
    case 3: str3="def";break;
    case 4: str3="ghi";break;
    case 5: str3="jkl";break;
    case 6:str3="mno"; break;
    case 7:str3="pqrs";break;
    case 8:str3="tuv";break;
    case 9:str3="wxyz";break;
    default:str3="";
}
string s=""+str1[0]+str2[0]+str3[0];
cout<<s;
for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
    { 
        for (int k = 0; k < n; k++)
        {   string s=""+str1[i]+str2[j]+str3[k];
            cout<<s<<" ";
            poss.push_back(s);
        }
        
    }
    
}
return poss;
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