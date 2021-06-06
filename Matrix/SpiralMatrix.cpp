#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> ans;
        int leftcol=0,rightcol=n-1;int count=0;
        
        int topleft=0,bottomleft=m-1;
        while(topleft<=bottomleft && rightcol>=leftcol){
            //cout<<count++<<" ";
            for(int i=topleft;i<=rightcol;i++){
                
                ans.push_back(matrix[topleft][i]);
            }
            
            topleft++;
            
            for(int i=topleft;i<=bottomleft;i++){
                ans.push_back(matrix[i][rightcol]);
            }
            
            rightcol--;
            if(topleft<=bottomleft){
            for(int i=rightcol;i>=leftcol;i--){
                //cout<<"in"<<" ";
                ans.push_back(matrix[bottomleft][i]);
            }
            
            bottomleft--; 
            }
            if(leftcol<=rightcol){
            for(int i=bottomleft;i>=topleft;i--){
                ans.push_back(matrix[i][leftcol]);
            }
            
            leftcol++; 
            }
        }
        return ans;
    }
};