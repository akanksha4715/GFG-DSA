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
void change(TreeNode* t1,TreeNode* t2){
        if(t1==NULL && t2==NULL)
            return ;
        if((t1==NULL && t2!=NULL) || (t1!=NULL && t2==NULL))
            return ;
        t1->val = t2->val; 
        change(t1->right,t2->left);
        change(t1->left,t2->right);
        //return  (mirror(t1->right,t2->left)) && mirror(t1->left,t2->right);
    }
    bool mirror(TreeNode* t1,TreeNode* t2){
        if(t1==NULL && t2==NULL)
            return true;
        if(t1==NULL || t2==NULL)
            return false;
        return  (mirror(t1->right,t2->left)) && mirror(t1->left,t2->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(mirror(root,root))
        change(root,root);
        else
        return 0;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){           
            TreeNode *rot =q.front();
            q.pop();
            if(rot==NULL){
                vec.push_back(v);
                v.clear();
                if(!q.empty())
                q.push(NULL);
            }
            else{
                cout<<rot->val<<" ";
                v.push_back(rot->val);
                if(rot->left!=NULL)
                q.push(rot->left);
                if(rot->right!=NULL)
                q.push(rot->right);
            }
        }
        return vec;
    }

    
    
    int main(){
        TreeNode *root = new TreeNode(1);
        root->left=new TreeNode(2);
        root->right=new TreeNode(9);
        root->left->right=new TreeNode(9);
        root->left->left=new TreeNode(5);
        root->right->right=new TreeNode(3);
        root->right->left=new TreeNode(4);
        isSymmetric(root);
        vector<vector<int>> va=levelOrder(root);
    }