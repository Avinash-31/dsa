// using memoization
class Solution {
public:
    int fn(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
        //base case
        if(i==0 && j==0){
            return dp[0][0] = grid[0][0];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // other cases
        int up = grid[i][j] + fn(i-1,j,grid,dp);      
        int left = grid[i][j] + fn(i,j-1,grid,dp);     
        return dp[i][j] = min(left,up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,grid,dp);
    }
};

// using tabulation
frmo space optimization

// space optim ization
#include<bits/stdc++.h>
class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j] = grid[0][0];
                }
                else{
                    int up = grid[i][j];
                    if(i>0){
                        up+=prev[j];
                    }
                    else
                        up+=1e9;
                    int left = grid[i][j];
                    if(j>0){
                        left+=temp[j-1];
                    }
                    else
                        left+=1e9;
                    temp[j] = min(up,left);
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};