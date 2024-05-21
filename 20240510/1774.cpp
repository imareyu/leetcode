class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        sort(baseCosts.begin(), baseCosts.end());
        if(baseCosts[0] >= target)
        {
            return baseCosts[0];
        }
        int n = toppingCosts.size();
        vector<set<int>> dp(n);
        
        for(int i = 0;i < n;i++)
        {
            dp[i].insert(0);
            dp[i].insert(toppingCosts[i]);
            dp[i].insert(toppingCosts[i]*2);
            if(i == 0)
                continue;
            dp[i].insert(dp[i-1].begin(), dp[i-1].end());
            for(int sum:dp[i-1])
            {
                int nsum = sum + toppingCosts[i];
                dp[i].insert(nsum);
                if(nsum > target)
                    break;
                nsum += toppingCosts[i];
                dp[i].insert(nsum);
            }
        }
        auto& topp = dp[n-1];
        int ret = baseCosts[0];

        for(int i = 0;i < baseCosts.size();i++)
        {
            //cout<<"baseCosts["<<i<<"]="<<baseCosts[i]<<endl;
            for(auto sum:topp)
            {
                //cout<<sum<<endl;
                int newsum = baseCosts[i]+sum;
                if(newsum > target)
                {
                    if(abs(newsum-target) < abs(ret-target))
                    {
                        ret = newsum;
                    }
                    else
                    {
                        if(abs(newsum-target) == abs(ret-target))
                        {
                            ret = min(ret, newsum);
                        }
                    }
                    break;
                }
                if(abs(newsum-target) < abs(ret-target))
                {
                    ret = newsum;
                }
                else
                {
                    if(abs(newsum-target) == abs(ret-target))
                    {
                        ret = min(ret, newsum);
                    }
                }
            }
            //cout<<"ret="<<ret<<endl;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/closest-dessert-cost/