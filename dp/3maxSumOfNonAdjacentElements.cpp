// recurrence relation

#include <bits/stdc++.h> 

int fn(int ind,vector<int> &nums){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    int pick = nums[ind] + fn(ind-2,nums);
    int notPick = 0 + fn(ind-1,nums);

    return max(pick,notPick); 
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return fn(n-1,nums);
}

// Using dp (memoization)

#include <bits/stdc++.h> 

int fn(int ind,vector<int> &nums,vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int pick = nums[ind] + fn(ind-2,nums,dp);
    int notPick = 0 + fn(ind-1,nums,dp);

    return dp[ind] = max(pick,notPick); 
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return fn(n-1,nums,dp);
}

// Using Tabulation method
#include <bits/stdc++.h> 


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    int neg = 0;
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1)
            take+=dp[i-2];
        int notTake = 0 + dp[i-1];
        dp[i] = max(take,notTake);
    }
    return dp[n-1];
}

// after space optimization

#include <bits/stdc++.h> 


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1)
            take+=prev2;
        int notTake = 0 + prev;
        int curi = max(take,notTake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}