//return the intersection pt of two LL
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
int intersectPoint(Node* head1, Node* head2)
{
    Node *ptr1=head1;
    Node *ptr2=head2;
    int c1=0,c2=0,c;
    while(ptr1!=NULL){
        c1++;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        c2++;
        ptr2=ptr2->next;
    }
    c=c1-c2;
    c=abs(c);
    ptr1=head1;
    ptr2=head2;
    if(c1>c2){
        while(c1!=c2){
            ptr1=ptr1->next;
            c1--;
        }
    }
    else{
        while(c1!=c2){
            ptr2=ptr2->next;
            c2--;
        }
    }
    while(ptr1!=NULL || ptr2!=NULL){
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        else{
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    return -1;
}