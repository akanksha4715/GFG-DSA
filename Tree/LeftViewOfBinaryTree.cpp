#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(nullptr),right(NULL){}
    TreeNode(int x,TreeNode *left,TreeNode *right) : val(x),left(left),right(right){}
};
void printleft(TreeNode *root){
    if(!root)
    cout<<-1;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){      
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode *rot=q.front();
            q.pop();
            if(i==0)
            cout<<rot->val<<" ";
            if(rot->left)
            q.push(rot->left);
            if(rot->right)
            q.push(rot->right);
        }
    }
}
int main(){
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(100);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    printleft(root);
    return 0;
}