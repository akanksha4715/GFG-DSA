#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string> sett;
        bool present=false;
        for(int i=0;i<n;i++){
            sett.insert(wordList[i]);
            if(wordList[i]==endWord)
                present =true;
        }
        if(!present)
            return false;
        sett.erase(beginWord);
        queue<string> q;int res=0;
        q.push(beginWord);
        while(!q.empty()){
            res++;
            int size=q.size();
            while(size--){
                string str=q.front();
                int len=str.length();
                q.pop();
                for(int i=0;i<len;i++){
                    string temp=str;
                    for(char j='a';j<='z';j++){
                        temp[i]=j;
                        if(temp==endWord)
                            return res+1;
                        if(sett.find(temp)!=sett.end()){
                            sett.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};