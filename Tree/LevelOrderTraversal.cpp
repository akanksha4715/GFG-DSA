#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
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
                v.push_back(rot->val);
                if(rot->left!=NULL)
                q.push(rot->left);
                if(rot->right!=NULL)
                q.push(rot->right);
            }
        }
        return vec;
    }
    
};