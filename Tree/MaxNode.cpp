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
int msize(TreeNode *root){
    if(root==NULL)
    return INT_MIN;
    return max(root->val,max(msize(root->left),msize(root->right)));
}
int main(){
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(100);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    //TreeNode *root1=new TreeNode();
    cout<<msize(root)<<" ";
    return 0;
}