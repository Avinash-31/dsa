class Solution {
public:
    int climbStairs(int n) {
        //similar like fibornacci series
        int oneStep = 1;
        int zeroStep = 1;
        for(int i=2;i<=n;i++){
            int curi = oneStep+zeroStep;
            zeroStep = oneStep;
            oneStep = curi;
        }
        return oneStep;
    }
};

or else can use 

dp[0]=1,dp[1]=1;
for(i = 2 to n){
    dp[i]=(dp[i-1]+dp[i-2]);
}

but here space complexity is O(n)
whereas in the above code space complexity is O(1)