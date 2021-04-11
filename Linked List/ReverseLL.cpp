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
    cout<<"Before"<<endl;
    print(head);
    cout<<endl<<"After"<<endl;
    head=reversal(head);
    print(head);
    return 0;
}
