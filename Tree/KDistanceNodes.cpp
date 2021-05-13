#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {};
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {};
    TreeNode(int x, TreeNode *left,TreeNode *right) : val(x),left(left),right(right) {};
};
void knodes(TreeNode *root,int k){
    if(root==NULL)
    return;
    if(k==0){
        cout<<root->val<<" ";
        return;
    }
    knodes(root->left,k-1);
    knodes(root->right,k-1);
}
int main(){
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
	int k=2;
    knodes(root,k);
    return 0;
}