class Solution {
public:
    bool detectCapitalUse(string word) {
        int lowCount = 0;
        int uppCount = 0;
        for(char ch:word)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                lowCount++;
            }
            else
            {
                uppCount++;
            }
        }
        if(lowCount == word.size() || uppCount == word.size())
        {
            return true;
        }
        if(uppCount == 1 && word[0] >= 'A' && word[0] <= 'Z')
        {
            return true;
        }

        return false;

    }
};
//https://leetcode.cn/problems/detect-capital/