class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int,vector<pair<int,int>>> endTimeData;
        int n = startTime.size();
        int maxret = 0;

        for(int i = 0;i < n;i++)
        {
            endTimeData[endTime[i]].emplace_back(startTime[i], profit[i]);
        }

        vector<pair<int,int>> dp;//1为结束点，2为对应的最大值

        for(auto it = endTimeData.begin();it != endTimeData.end();it++)
        {
            int maxval = 0;
            for(auto [start, val]:it->second)
            {
                if(dp.empty())
                {
                    maxval = max(maxval, val);
                }
                else
                {
                    maxval = max(val, maxval);
                    for(int j = dp.size()-1;j >= 0;j--)
                    {
                        if(dp[j].first <= start)
                        {
                            maxval = max(maxval, dp[j].second + val);
                            break;
                        }
                    }
                }
            }
            //cout<<it->first<<" "<<maxval<<endl;
            if(dp.empty())
                dp.emplace_back(it->first, maxval);
            else
            {
                if(maxval <= dp.back().second)
                {
                    dp.emplace_back(dp.back());
                }
                else
                {
                    dp.emplace_back(it->first, maxval);
                }
            }
            maxret = max(dp.back().second, maxret);
        }
        return maxret;
    }
};
//https://leetcode.cn/problems/maximum-profit-in-job-scheduling/