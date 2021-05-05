#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    string temp;
    cin>>n;
    vector<string> vec;
    vector<int> vint;
    vector<vector<int>> v;
    for(int i=0;i<=n;i++){
        getline(cin,temp);
        vec.push_back(temp);
    }
    vec.erase(vec.begin());
    cout<<"=============="<<endl;
    for(int i=0;i<n;i++){
        string word=vec[i];
        string sp=" ";
        int start=0;
        int end=word.find(sp);
        while(end!=-1){
            vint.push_back(stoi ( word.substr(start,end-start) ));
            start=end+sp.size();
            end=word.find(sp,start);
        }
        cout<<start<<end<<endl;
     vint.push_back(stoi ( word.substr(start,end-start) ));
    }
    int m=vint.size();
    m=m/n;
    cout<<"=============="<<endl;
    int k=0;
    for(int i=0;i<n;i++){
        vector<int> v1;
        for (int j = 0; j < m; j++)
        {
            v1.push_back(vint[k]);
            k++;
        }
        v.push_back(v1);
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int val : v[i])
        {
            cout<<val<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}