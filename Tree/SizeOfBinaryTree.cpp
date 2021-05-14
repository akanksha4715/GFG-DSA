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
int size(TreeNode *root){
    if(root==NULL)
    return 0;
    return 1+size(root->left)+size(root->right);
}
int lotsize(TreeNode *root){ //using level order traversal
    if(root==NULL)
    return 0;
    queue<TreeNode*> q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        TreeNode *rot=q.front();
        q.pop();
        count++;
        if(rot->left!=NULL)
        q.push(rot->left);
        if(rot->right!=NULL)
        q.push(rot->right);
    }
    return count;
}
int main(){
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    cout<<size(root)<<" "<<lotsize(root);
    return 0;
}