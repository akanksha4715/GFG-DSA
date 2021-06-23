#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pad={ 
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        vector<string> res={""};
        int l=digits.length();
        if(l==0)
            return {};
        for(int i=0;i<l;i++){
            int x=digits[i]-'0';
            vector<string> temp;
            for(auto e:res){
                for(auto c:pad[x]){
                    temp.push_back(e+c);
                }
            }
            res=temp;
        }
        return res;
    }
};