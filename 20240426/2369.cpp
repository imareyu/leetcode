class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);

        dp[0] = 0;
        if(nums[0] == nums[1])
            dp[1] = 1;
        if(n >= 3)
        {
            if((nums[2] - nums[1] == 1 && nums[1]-nums[0] == 1)||(nums[0] == nums[1]&&nums[1] == nums[2]))
            {
                dp[2] = 1;
            }
        }
        for(int i = 3;i < n;i++)
        {
            if(dp[i-2] == 1 && nums[i] == nums[i-1])
            {
                dp[i] = 1;
            }
            else
            {
                if(dp[i-3] == 1 && ((nums[i]-nums[i-1] == 1&&nums[i-1]-nums[i-2] == 1) || (nums[i]==nums[i-1]&&nums[i] == nums[i-2])))
                {
                    dp[i] = 1;
                }
            }
        }
        return dp[n-1];
    }
};
//https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/?envType=daily-question