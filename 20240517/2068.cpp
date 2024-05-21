class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> chCount(26, 0);
        int n = word1.size();

        for(int i = 0;i < n;i++)
        {
            chCount[word1[i]-'a']++;
        }

        for(int i = 0;i < n;i++)
        {
            chCount[word2[i]-'a']--;
        }
        for(int i = 0;i < 26;i++)
        {
            if(chCount[i] > 3 || chCount[i] < -3)
            {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent/