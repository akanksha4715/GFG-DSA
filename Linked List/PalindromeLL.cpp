#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
node* reversal(node *head){
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* nextt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
    return prev;

}
node *findmid(node *head){
    node *slow=head;
    node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //cout<<"Slow "<<slow->data;
    return slow;
}
bool check(node *head){
    node *ptr=head;
    if(head==NULL)
    return false;
    if(head->next==NULL)
    return true;
    node *mid =findmid(head);
   // cout<<"Mid is "<<mid->data;
    node *rev=reversal(mid->next);
    while(rev!=NULL){
        if(ptr->data != rev->data)
        return false;
        rev=rev->next;
        ptr=ptr->next;
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
void print(node *head){
    node *ptr = NULL;
    ptr=head;
    while(ptr->next!=NULL)
    {
       cout<<ptr->data<<" ";
       ptr=ptr->next;
    }
    cout<<ptr->data<<" ";
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