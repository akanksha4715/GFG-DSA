#include<iostream>
#include<stack>
#include<vector>
using namespace std;
deque<int> findans(vector<int> arr){
    int n=arr.size();
    stack<int> st;
    deque<int> ans;
    st.push(arr[n-1]);
    ans.push_front(-1);
    //cout<<-1<<" ";
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])
        st.pop();
        if(st.empty())
        ans.push_front(-1);
        //cout<<-1<<" ";
        else
        //cout<<st.top()<<" ";
        ans.push_front(st.top());
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr={5,15,10,8,6,12,18};
    deque<int> vec=findans(arr);
    for(auto x:vec)
    cout<<x<<" ";
    
}