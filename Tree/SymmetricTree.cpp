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
    bool mirror(TreeNode* t1,TreeNode* t2){
        if(t1==NULL && t2==NULL)
            return true;
        if(t1==NULL || t2==NULL)
            return false;
        return (t1->val == t2->val) && (mirror(t1->right,t2->left)) && mirror(t1->left,t2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root,root);
    }
    int main(){
        TreeNode *root = new TreeNode(1);
        root->left=new TreeNode(2);
        root->right=new TreeNode(2);
        root->left->right=new TreeNode(3);
        root->right->right=new TreeNode(3);
        cout<<isSymmetric(root);
    }