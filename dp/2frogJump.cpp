#include <bits/stdc++.h>

int fn(int ind,vector<int> &heights){
    if(ind == 0) return 0;
    int left = fn(ind-1,heights) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = fn(ind-2,heights) + abs(heights[ind]-heights[ind-2]);
    }
    return min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int mini = fn(n-1,heights);
    return mini;
}

---> above code results in TLE

 #include <bits/stdc++.h>

int fn(int ind,vector<int> &heights,vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left = fn(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = fn(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind] =  min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    int mini = fn(n-1,heights,dp);
    return mini;
}

-- above code using dp


#include <bits/stdc++.h>


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1]; 
}


--- above code using tabulation


#include <bits/stdc++.h>


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev1 = 0; //prev1 -- dp[i-1]
    int prev2 = 0; //prev2 -- dp[i-2]
    for(int i=1;i<n;i++){
        int fs = prev1 + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = prev2 + abs(heights[i]-heights[i-2]);
        }
        int curi = min(fs,ss);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}


--- space optimised code