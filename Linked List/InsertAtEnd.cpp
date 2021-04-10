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
void insertin(node *head,int x){
    node *temp = new node(x);
    temp->next=NULL;
    node *ptr = head;    
    while (ptr->next!=NULL)
       ptr=ptr->next;
     ptr->next=temp; 
}
void print(node *head){
    node *ptr = NULL;
    ptr=head;
    do
    {
       cout<<ptr->data<<" ";
       ptr=ptr->next;
    }while (ptr!=NULL);
   // cout<<ptr->data<<" ";
}
int main(){
    int n,x;
    cin>>n;
    cin>>x;
    node *head=new node(x);
    head->next=NULL; 
    for(int i=1;i<n;i++){       
        cin>>x;
        insertin(head,x);
    }
    print(head);
}

// int main(){
//     //cout<<"Enter no of nodes";
//     node *n1= new node(10);
//     node n2=node(2);
//     cout<<n2.data;
//     cout<<n1->data;
//     return 0;

// }