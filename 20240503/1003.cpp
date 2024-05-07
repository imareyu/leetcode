class Solution {
public:
    bool isValid(string s) {
        string sta;

        for(int i = 0;i < s.size();i++)
        {
            sta += s[i];
            int n = sta.size();
            if(sta.size() >= 3 && sta[n-1] == 'c' && sta[n-2]=='b' && sta[n-3] =='a')
            {
                sta.pop_back();
                sta.pop_back();
                sta.pop_back();
            }
        }
        if(sta.empty())
            return true;
        return false;
    }
};
//https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/description/