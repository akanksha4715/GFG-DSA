#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
bool match(char a,char b)
{
    return ( (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']') );
}
bool chk(string s){
    stack<char> st;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        st.push(s[i]);
        else {
            if(st.empty())
            return false;
            if(match(st.top(),s[i]))
            {
                st.pop();
            }
            else
            {
                return false;
            }            
        }
    }
    return (st.empty());
}
int main(){
    string s;
    getline(cin,s);
    if(chk(s))
    cout<<"Balanced";
    else
    {
        cout<<"Not Balanced";
    } 
    return 0;
}