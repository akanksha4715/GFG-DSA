#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
    ans.push_back(n);
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && vec[st.top()]>=vec[i])
        st.pop();
        if(st.empty())
        ans.push_front(n);
        else
        ans.push_front(st.top());
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& vec) {
        deque<int> prev,next;
        prev=prevsmall(vec);
        next=nextsmall(vec);
        int n=vec.size();
        int maxx=INT16_MIN;
        for(int i=0;i<n;i++){
            maxx=max(maxx, vec[i]*(next[i]-prev[i]-1));
        }
        return maxx;
    }
};