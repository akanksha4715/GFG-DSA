#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node* sortedMerge(Node* head1, Node* head2)  
{  if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;

    Node *ptr1=head1;
    Node *ptr2=head2;
    Node *head=NULL;
    Node *tail=NULL;
    if(ptr1->data <= ptr2->data){
        head=ptr1;
        tail=ptr1;
        ptr1=ptr1->next;
    }
    else{
        head=ptr2;
        tail=ptr2;
        ptr2=ptr2->next;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data <= ptr2->data){
            tail->next=ptr1;
            tail=ptr1;
            ptr1=ptr1->next;
        }
        else{
            tail->next=ptr2;
            tail=ptr2;
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL)
    tail->next=ptr2;
    else
    tail->next=ptr1;
    return head;
} 