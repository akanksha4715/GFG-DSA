#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
bool check(node *head){
    stack<int> st;
    node *ptr=head;
    if(head==NULL)
    return false;
    if(head->next==NULL)
    return true;
    while(ptr!=NULL){
        st.push(ptr->data);
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL){
        if(st.top()!=ptr->data)
        return false;
        ptr=ptr->next;
        st.pop();
    }
    return true;
}
node* insertin(node *head,int x){
    node *temp = new node(x);
    temp->next=NULL;
    node *ptr = head;    
    while (ptr->next!=NULL)
       ptr=ptr->next;
     ptr->next=temp; 
     return head;
}
int main(){
    int n,x;
    cin>>n;
    cin>>x;
    node *head=new node(x);
    head->next=NULL; 
    for(int i=1;i<n;i++){       
        cin>>x;
        head=insertin(head,x);
    }
    bool a=check(head);
    cout<<endl<<a;
    return 0;
}