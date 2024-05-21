class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> chCount;

        for(int i = 0;i < s.size();i++)
        {
            chCount[s[i]]++;
        }
        for(int i = 0;i < t.size();i++)
        {
            chCount[t[i]]--;
        }
        int ret = 0;

        for(auto [ch, count]: chCount)
        {
            ret += abs(count);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/