#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    // choosing the first element as pivot
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while (arr[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    // placing the pivot to the correct place
    swap(arr[low],arr[j]);
    return j;
}

void mergeSort(vector<int> &arr,int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        mergeSort(arr,low,pivot-1);
        mergeSort(arr,pivot+1,high);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    mergeSort(arr,0,n-1);
     for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}