class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> strCount(26,vector<int>(26, 0));
        int n = words.size();

        for(int i = 0;i < n;i++)
        {
            int x = words[i][0]-'a';
            int y = words[i][1]-'a';
            strCount[x][y]++;
        }

        int ret = 0;
        for(int x = 0;x < 26;x++)
        {
            for(int y = x+1;y < 26;y++)
            {
                int mn = min(strCount[x][y], strCount[y][x]);
                ret += 4 * mn;
            }
        }
        bool one = false;
        for(int x = 0;x < 26;x++)
        {
            ret += (strCount[x][x]/2)*4;// 5 
            if(strCount[x][x]%2 == 1)
            {
                one = true;
            }
        }
        if(one)
            ret += 2;
        return ret;
    }
};
//https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words/