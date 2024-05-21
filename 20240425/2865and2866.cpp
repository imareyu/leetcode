class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> sta;
        vector<long long> dp1(n, 0);
        vector<long long> dp2(n, 0);

        dp1[0] = heights[0];
        sta.push(make_pair(heights[0], 0));
        for(int i = 0;i < n;i++)
        {
            while(!sta.empty())
            {
                auto [val, index] = sta.top();
                if(val > heights[i])
                {
                    sta.pop();
                }
                else
                {
                    break;
                }
            }
            if(sta.empty())
            {
                dp1[i] = (long long)heights[i] * (i+1);
            }
            else
            {
                int index = (sta.top()).second;
                dp1[i] = dp1[index] + (long long)heights[i]*(i-index);
            }
            sta.push(make_pair(heights[i], i));
        }

        dp2[n-1] = heights[n-1];
        while(!sta.empty())
            sta.pop();
        sta.push(make_pair(heights[n-1], n-1));
        for(int i = n-2;i >= 0;i--)
        {
            while(!sta.empty())
            {
                auto [val, index] = sta.top();
                if(val > heights[i])
                {
                    sta.pop();
                }
                else
                {
                    break;
                }
            }
            if(sta.empty())
            {
                dp2[i] = (long long)heights[i] * (n-i);//n = 9
            }
            else
            {
                int index = (sta.top()).second;
                dp2[i] = dp2[index] + (long long)heights[i]*(index-i);
            }
            sta.push(make_pair(heights[i], i));
        }
        long long ret = heights[0];
        for(int i = 0;i < n;i++)
        {
            long long sum = dp1[i] - heights[i] + dp2[i];
            if(sum > ret)
            {
                ret = sum;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/beautiful-towers-i/?envType=daily-question
//https://leetcode.cn/problems/beautiful-towers-ii/description/?envType=daily-question