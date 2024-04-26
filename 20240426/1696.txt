class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, less<pair<int,int>>> pq;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        pq.push(make_pair(dp[0], 0));
        for(int i = 1;i < n;i++)
        {
            while(!pq.empty())
            {
                auto [weight, index] = pq.top();
                if(i <= k+index)
                {
                    break;
                }
                else
                {
                    pq.pop();
                }
            }
            auto [weight, index] = pq.top();
            dp[i] = weight + nums[i];
            pq.push(make_pair(dp[i], i));            
        }
        return dp[n-1];
    }
};
//https://leetcode.cn/problems/jump-game-vi/description/?envType=daily-question