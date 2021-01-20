#include<iostream>
#include<algorithm>
using namespace std;
string palin(string s){
    int m=s.length();
    int dp[m][m];
    int start=0,end=0,len=1;
    for(int i=0;i<m;i++)
    dp[i][i]=1;

    for(int i=0;i<m-1;i++){
        if(s[i]==s[i+1]){
        dp[i][i+1]=1;
        start=i;end=i+1;len=2;
        }
        else
        {
            dp[i][i+1]=0;
        }       
    }

    for(int gap=2;gap<m;gap++){
        for(int i=0;i+gap<m;i++){
            int j=i+gap;
            if(s[i]==s[j]  && dp[i+1][j-1]==1){
                dp[i][j]=1;
                if(j-i+1>len){
                    start=i;
                    end=j;
                    len=j-i+1;
                }
            }
            else
            {
                dp[i][j]=0;
            }
            
        }
    }
    // char* pal=new char[len];int k=0;
    // for(int i=start;i<=end;i++){
    //     pal[k]=s[i];
    //     k++;
    // }
    string pal;
    int k=0;
    cout<<start<<" "<<end<<endl;
    pal=s.substr(start,len);
    return pal;
}
int main(){
    string s;
    getline(cin,s);
    cout<<palin(s);
    return 0;
}