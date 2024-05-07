class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int, int> count;
        count[INT_MAX] = INT_MAX;
        for(int num:nums)
        {
            count[num]++;
        }
        int ret = 0;
        vector<pair<int, int>> data;
        for(auto it = count.begin();it != count.end();it++)
        {
            //cout<<it->first<<"  "<<it->second<<endl;
            if(data.empty())
            {
                data.emplace_back(it->first, it->second);
            }
            else
            {
                int val = data.back().first;
                if(it->first - val == 1)
                {
                    data.emplace_back(it->first, it->second);
                }
                else
                {//不是连续的，可以处理下
                    //cout<<"bulianxu"<<endl;
                    vector<pair<int, int>> dp(data.size());//first表示占用，second不占用

                    int mx = 0;
                    dp[0].first = data[0].first * data[0].second;
                    mx = dp[0].first;
                    dp[0].second = 0;
                    for(int i = 1;i < dp.size();i++)
                    {
                        dp[i].first = dp[i-1].second + data[i].first * data[i].second;
                        dp[i].second = max(dp[i-1].first, dp[i-1].second);
                        mx = max(mx, dp[i].first);
                        mx = max(mx, dp[i].second);
                    }
                    data.clear();
                    ret += mx;
                    it--;
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/delete-and-earn/