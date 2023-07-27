class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //using xor approach
        int n = nums.size();
        int xori = 0;
        for(int i=0;i<n;i++){
            xori = xori^nums[i];
        }
        return xori;
    }
};