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
node* insertin(node *head,int x){
    node *temp = new node(x);
    temp->next=head;
    //temp->data=x;
    //head=temp;
    return temp;
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
    //head->next=NULL; 
    for(int i=1;i<n;i++){       
        cin>>x;
        head=insertin(head,x);
    }
    print(head);
}
