class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long allSum = 0;
        long long preSum = 0;
        int ret = 0;

        for(int i = 0;i < n;i++)
        {
            allSum += nums[i];
        }
        
        for(int i = 0;i < n-1;i++)
        {
            preSum += nums[i];
            if(allSum - preSum <= preSum)
            {
                ret++;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/number-of-ways-to-split-array/description/