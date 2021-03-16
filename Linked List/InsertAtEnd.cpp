#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int n){
        data=n;
        next=NULL;
    }
};
int main(){
    //cout<<"Enter no of nodes";
    node *n1= new node(10);
    node n2=node(2);
    cout<<n2.data;
    cout<<n1->data;
    return 0;

}