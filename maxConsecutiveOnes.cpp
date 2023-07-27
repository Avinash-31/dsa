class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //two pointer approach
        int n = nums.size();
        int oneInd = -1;
        int cnt = 0;
        int maxi = 0;
        //to get the first occurence of 1
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                oneInd = i;
                cnt++;
                break;
            }
        }

        //checkjing for multiple ones
        if(oneInd == n-1){
            return cnt;
        }
        for(int i=oneInd+1;i<n;i++){
            if(nums[i]!=1){
                maxi = max(maxi,cnt);
                cnt=0;
                continue;
            }
            cnt++;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};