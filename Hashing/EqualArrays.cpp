 #include<vector>
 #include<iostream>
 #include<unordered_map>
 using namespace std;
 #define ll long long 
 bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        unordered_map<ll,ll> sett;
        for(int i=0;i<N;i++){
            sett[A[i]]++;
        }
        for(int i=0;i<N;i++){
            sett[B[i]]--;
        }
        for(auto k:sett){
            if(k.second!=0)
            return false;
        }
        return true;
        
    }