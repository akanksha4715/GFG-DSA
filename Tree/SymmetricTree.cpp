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
bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            int n=q.size();
            vector<int> vec;
            while(n--){
                TreeNode* x=q.front();
                q.pop();
                if(x==NULL){
                    int len=vec.size();
                    for(int i=0;i<len/2;i++){
                        if(vec[i]!=vec[n-i-1])
                            return false;
                    }
                    vec.clear();
                    if(!q.empty())
                        q.push(NULL);
                }
                else{
                    vec.push_back(x->val);
                    if(x->left)
                        q.push(x->left);
                    if(x->right)
                        q.push(x->right);
                }
            }
        }
        return true;
    }
    int main(){
        TreeNode *root = new TreeNode(1);
        root->left=new TreeNode(2);
        root->right=new TreeNode(2);
        root->left->right=new TreeNode(3);
        root->right->right=new TreeNode(3);
        cout<<isSymmetric(root);
    }