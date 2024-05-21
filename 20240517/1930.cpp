class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, vector<int>> indexs;
        int n = s.size();
        int ret = 0;

        for(int i = 0;i < n;i++)
        {
            indexs[s[i]].emplace_back(i);
        }
        for(auto& [ch, vec]:indexs)
        {
            if(vec.size() >= 3)
            {
                ret++;
            }
            if(vec.size() > 1)
            {
                int left = vec[0];
                int right = vec.back();

                for(auto& [ch2, vec2]:indexs)
                {
                    if(ch != ch2)
                    {
                        int index = upper_bound(vec2.begin(), vec2.end(), left) - vec2.begin();
                        if(index >= vec2.size())
                        {
                            continue;
                        }
                        if(vec2[index] < right)
                        {
                            ret++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/description/