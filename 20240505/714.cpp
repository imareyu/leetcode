class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<pair<int,int>> dp(n);//first持有了，second卖出了
        dp[0].first = -prices[0];
        dp[0].second = 0;
        int mxret = 0;
        for(int i = 1;i < n;i++)
        {
            dp[i].first = max(dp[i-1].second-prices[i], dp[i-1].first);
            dp[i].second = max(dp[i-1].first + prices[i]-fee,dp[i-1].second);
            mxret = max(mxret, dp[i].first);
            mxret = max(mxret, dp[i].second);
        }

        return mxret;
    }
};
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/