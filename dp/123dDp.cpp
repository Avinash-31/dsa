// memoization
#include <bits/stdc++.h> 
int fn(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    // out of range case
    int m = grid.size();
    int n = grid[0].size();
    if(j1<0 || j2<0 || j1>n-1 || j2>n-1)
        return -1e8;
    // base case
    if(i==m-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else
            return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
    // other cases
    int maxi = -1e8;
    for(int d1=-1;d1<2;d1++){
        for(int d2=-1;d2<2;d2++){
            int value = 0;
            if (j1 == j2) {
              value = grid[i][j1];
            } else {
              value = grid[i][j1] + grid[i][j2];
            }
            value+=fn(i+1,j1+d1,j2+d2,grid,dp);
            maxi=max(maxi,value);
            
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return fn(0,0,c-1,grid,dp);
}