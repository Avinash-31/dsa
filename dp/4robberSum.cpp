#include <bits/stdc++.h> 

int fn(vector<int> &temp){
    int n = temp.size();
    if(n==1) return temp[0];
    int prev = temp[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = temp[i];
        if(i>1){
            take+=prev2;
        }
        int notTake = 0 + prev;
        int curi = max(take,notTake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }
    if(n==0) return 0;
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        // Including till last except the first one
        if(i!=0){
            temp1.push_back(valueInHouse[i]);
        }
        // first to last ommiting last
        if(i!=(n-1)){
            temp2.push_back(valueInHouse[i]);
        }
    }
    int ans1 = fn(temp1);
    int ans2 = fn(temp2);
    return max(ans1,ans2);
}