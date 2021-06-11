#include<bits/stdc++.h>
using namespace std;
deque<int> prevsmall(vector<int> vec){
    int n=vec.size();
    stack<int> st;
    deque<int> ans;
    ans.push_back(-1);
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && vec[st.top()]>=vec[i])
        st.pop();
        if(st.empty())
        ans.push_back(-1);
        else
        ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
deque<int> nextsmall(vector<int> vec){
    int n=vec.size();
    stack<int> st;
    deque<int> ans;
    ans.push_back(n+1);
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && vec[st.top()]>=vec[i])
        st.pop();
        if(st.empty())
        ans.push_front(n+1);
        else
        ans.push_front(st.top());
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int> vec={2,1,5,6,2,3};
    deque<int> prev,next;
    prev=prevsmall(vec);
    next=nextsmall(vec);
    for(auto x:next)
    cout<<x<<" ";
    return 0;
}