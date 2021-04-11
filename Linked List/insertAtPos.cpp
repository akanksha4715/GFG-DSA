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
node* insertat(node *head,int x,int n){
    node *ptr=head;
    node *temp = new node(x);
    if(n==1){
        temp->next=head;
        return temp;
    }
    else{
    int count=1;
    while(count<n-1){
        ptr=ptr->next;
        count++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;
    }
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
    cout<<"Before insertion"<<endl;
    print(head);
    cout<<endl<<"Insert __ at __"<<endl;
    cin>>x>>n;
    head=insertat(head,x,n);
    print(head);
    return 0;
}
