class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long, long long>> dp(n);//first是当前奇数长度的最大值
        dp[0].first = nums[0];
        dp[0].second = 0;
        long long ret = nums[0];
        for(int i = 1;i < n;i++)
        {
            dp[i].first = max(dp[i-1].first, dp[i-1].second + nums[i]);
            dp[i].first = max(dp[i].first, (long long)nums[i]);
            dp[i].second = max(dp[i-1].first - nums[i], dp[i-1].second);
        }
        ret = max(dp[n-1].first, dp[n-1].second);
        return ret;
    }
};
//https://leetcode.cn/problems/maximum-alternating-subsequence-sum/