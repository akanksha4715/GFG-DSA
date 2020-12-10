#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
    int value;
    int weight;
};
bool mycmp(Item a,Item b){
    double r1=(double) a.value/a.weight;
    double r2=(double) b.value/b.weight;
    return r1>r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,mycmp);
    double res=0;
    for(int i=0;i<n;i++){
        if(W==0)
        {
            /* code */
            return res;
        }       
        else if(arr[i].weight<=W){
            res+=arr[i].value;
            W=W-arr[i].weight;
        }
        else{          
           res += arr[i].value * ((double) W / arr[i].weight);           
        }       
    }
    return res;
}
int main(){
    int n , W ;
    cin>>n>>W;
    Item arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].value>>arr[i].weight;
    }
	cout<<fractionalKnapsack(W, arr, n); 

	return 0;

}

