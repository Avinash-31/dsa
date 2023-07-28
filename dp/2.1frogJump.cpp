int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
    int jumpSteps;
    for(int i=1;i<n;i++){
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                jumpSteps = dp[i-j]+abs(height[i]-height[i-j]);
                minSteps = min(minSteps,jumpSteps);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}