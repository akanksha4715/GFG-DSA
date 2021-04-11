//Remove duplicate values from sorted LL
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
node* removal(node *head){
    if(head->next==NULL){
        return head;
    }
    node* prev=head;
    node* curr=head->next;
    while(curr!=NULL){
        if(prev->data==curr->data){
            node *temp=curr->next;
            prev->next=temp;
            delete(curr);
            curr=temp;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
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
    head=removal(head);
    print(head);
    return 0;
}