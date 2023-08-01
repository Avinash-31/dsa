// memoization
class Solution {
public:
    int fn(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp,int n){
        //base case
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down = triangle[i][j] + fn(i+1,j,triangle,dp,n);
        int diag = triangle[i][j] + fn(i+1,j+1,triangle,dp,n);
        return dp[i][j] = min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       vector<vector<int>> dp(n,vector<int>(n,-1));
       return fn(0,0,triangle,dp,n); 
    }
};

// tabulation
 vector<vector<int>> dp(n,vector<int>(n,0));
       //storing the last vector
       for(int j=0;j<n;j++){
           dp[n-1][j] = triangle[n-1][j];
       }
       //logic 
       for(int i=n-2;i>=0;i--){
           for(int j=i;j>=0;j--){
               int down = triangle[i][j]+dp[i+1][j];
               int diag = triangle[i][j]+dp[i+1][j+1];
               dp[i][j] = min(down,diag);
           }
       }
       return dp[0][0]; 

    //    space optimization
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       vector<int> front(n,0) ,curr(n,0);
       //storing the last vector
       for(int j=0;j<n;j++){
           front[j] = triangle[n-1][j];
       }
       //logic 
       for(int i=n-2;i>=0;i--){
           for(int j=i;j>=0;j--){
               int down = triangle[i][j]+front[j];
               int diag = triangle[i][j]+front[j+1];
               curr[j] = min(down,diag);
           }
           front = curr;
       }
       return front[0]; 
    }