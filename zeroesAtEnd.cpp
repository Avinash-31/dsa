class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //two pointer approach
        int n = nums.size();
        int zeroInd;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroInd = i;
                break;
            }
        }
        for(int j=zeroInd+1;j<n;j++){
            if(nums[j]!=0){
                swap(nums[j],nums[zeroInd]);
                zeroInd ++;
            }
        }
    }
};