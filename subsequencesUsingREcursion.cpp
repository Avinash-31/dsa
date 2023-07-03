#include<bits/stdc++.h>
using namespace std;

void printSubSeq(int ind,vector<int> &ds,int arr[],int n){

    //base condition
    if(ind == n){
        for(auto it : ds)
            cout<<it<<" ";
        if(ds.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }

    //adding (take situation)
    ds.push_back(arr[ind]);
    printSubSeq(ind+1,ds,arr,n);

    // removing (not-take situation)
    ds.pop_back();
    printSubSeq(ind+1,ds,arr,n);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ds;
    printSubSeq(0,ds,arr,n);
}