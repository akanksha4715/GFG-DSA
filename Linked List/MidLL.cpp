#include<iostream>
using namespace std;
struct node{
    int val;
    node *next;
    node(int x){
        val=x;
        next=NULL;
    }
};
int mid(node *head,int a){
    node *slow=head;
    node *fast=head;
    while(fast->next!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->val;
}
node *insert(node *head,int a){

}
int main(){
    int n,x;
    node *head;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insert(head,x);
    }
    return 0;
}