class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b)
        {
            if(a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });
        int n = strs.size();
        vector<vector<int>> shash(strs.size(), vector<int>(26, 0));

        for(int i = 0;i < strs.size();i++)
        {
            for(char ch:strs[i])
            {
                shash[i][ch-'a']++;
            }
        }
        int maxlen = -1;
        if(strs[n-1] != strs[n-2])
            return strs[n-1].size();
        for(int i = n-2;i >= 0;i--)
        {
            if(i+1 < n && strs[i] == strs[i+1])
            {
                continue;
            }
            if(i-1 >= 0 && strs[i] == strs[i-1])
            {
                continue;
            }
            int j = i+1;
            for(;j < strs.size();j++)
            {
                if(strs[i].size() == strs[j].size())
                {
                    if(strs[i] == strs[j])
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                deque<char> dq(strs[i].begin(),strs[i].end());
                int k = 0;
                while(!dq.empty() && k < strs[j].size())
                {
                    if(strs[j][k] == dq.front())
                    {
                        dq.pop_front();
                    }
                    k++;
                }
                if(dq.empty())
                {//是子序列
                    break;
                }
            }
            if(j == strs.size())
            {
                maxlen = max(maxlen, (int)strs[i].size());
            }
        }

        return maxlen;
    }
};
//https://leetcode.cn/problems/longest-uncommon-subsequence-ii/description/