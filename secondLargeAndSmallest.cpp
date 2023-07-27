#include<bits/stdc++.h>
using namespace std;

void largeSmall(int arr[],int n){
    if(n==0 || n==1){
        cout<<"No seconds"<<endl;
    }
    int small = INT_MAX,secondSmall = INT_MAX;
    int large = INT_MIN,secondLarge = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]<small){
            small = arr[i];
        }

        if(arr[i]>large){
            large = arr[i];
        }
    }

    for(int i =0;i<n;i++){
        if(arr[i]<secondSmall && arr[i]!=small)
            secondSmall = arr[i];
        
        if(arr[i]>secondLarge && arr[i]!=large)
            secondLarge = arr[i];
    }

    cout<<"Second Largest Number : "<<secondLarge<<endl<<"Second Smallest Number : "<<secondSmall;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    largeSmall(arr,n);

}