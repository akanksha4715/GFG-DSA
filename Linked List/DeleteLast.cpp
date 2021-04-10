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
void deletelast(node *head){
    node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    delete(ptr->next);
    ptr->next=NULL;
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
    do
    {
       cout<<ptr->data<<" ";
       ptr=ptr->next;
    }while (ptr->next!=NULL);
    cout<<ptr->data<<" ";
}
int main(){
    int n,x;
    cin>>n;
    cin>>x;
    node *head=new node(x);
    //cout<<"u";
    head->next=NULL; 
    for(int i=1;i<n;i++){       
        cin>>x;
        head=insertin(head,x);
    }
    cout<<"Before deletion"<<endl;
    print(head);
    cout<<endl<<"After deletion"<<endl;
    deletelast(head);
    print(head);
    return 0;
}
