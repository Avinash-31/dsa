#include<bits/stdc++.h>
using namespace std;

void printSubSum(int ind,vector<int> &ds,int arr[],int sum,int s,int n){
    // base case
    if(ind==n){
        if(s == sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    // take case
    s+=arr[ind];
    ds.push_back(arr[ind]);
    printSubSum(ind+1,ds,arr,sum,s,n);

    // not take case
    s-=arr[ind];
    ds.pop_back();
    printSubSum(ind+1,ds,arr,sum,s,n);
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ds;
    printSubSum(0,ds,arr,sum,0,n);
}