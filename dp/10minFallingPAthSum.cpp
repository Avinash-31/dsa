// using memoization
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>& dp){
        int n = matrix[0].size();

        //edge cases
        if(j<0 || j>=n){
            return 1e9;
        }

        //base case
        if(i==0){
            return matrix[0][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // other cases
        int up = matrix[i][j]+fn(i-1,j,matrix,dp);
        int diagLeft = matrix[i][j]+fn(i-1,j-1,matrix,dp);
        int diagRight = matrix[i][j]+fn(i-1,j+1,matrix,dp);

        return dp[i][j] = min(up,min(diagLeft,diagRight));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));

        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            int temp = fn(m-1,j,matrix,dp);
            mini = min(mini,temp);
        }
        return mini;
    }
};

// tabuilation
int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        //storing the 0th column
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        //logic
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j]+dp[i-1][j];

                int leftDiag = matrix[i][j];
                if((j-1)>=0)
                    leftDiag+=dp[i-1][j-1];
                else
                    leftDiag+=1e9;

                int rightDiag = matrix[i][j];
                if((j+1)<n)
                    rightDiag+=dp[i-1][j+1];
                else
                    rightDiag+=1e9;
                dp[i][j]=min(up,min(leftDiag,rightDiag));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini = min(mini,dp[m-1][j]);
        }
        return mini;
    }

// space o[tiomazation
