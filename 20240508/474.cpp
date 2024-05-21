class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> strsCount;

        for(string& str:strs)
        {
            int count0 = 0;
            int count1 = 0;
            for(char& ch:str)
            {
                if(ch == '0')
                {
                    count0++;
                }
                else
                {
                    count1++;
                }
            }
            strsCount.emplace_back(count0, count1);
        }

        sort(strsCount.begin(), strsCount.end());

        map<pair<int,int>, int> dp;
        //0为m数量，1为n数量,2为最大长度
        int ret = 0;
        for(auto [c0, c1] : strsCount)
        {
            map<pair<int,int>, int> addmap;
            if(c0 <= m && c1 <= n)
            {
                addmap[make_pair(c0, c1)] = 1;
                ret = max(ret, 1);
            }
            for(auto it:dp)
            {
                int dpc0 = it.first.first;
                int dpc1 = it.first.second;
                int len = it.second;
                if(c0+dpc0 <= m && c1+dpc1 <= n)
                {
                    addmap[make_pair(c0+dpc0,c1+dpc1)] = len+1;
                    ret = max(ret, len+1);
                }
            }
            for(auto it:addmap)
            {
                dp[it.first] = max(dp[it.first], it.second);
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/ones-and-zeroes/description/