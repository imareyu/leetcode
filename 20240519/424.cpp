class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n == k)
        {
            return n;
        }

        int left = 0;
        int right = 0;
        int maxlen = 1;
        vector<int> chCount(26, 0);
        chCount[s[0]-'A']++;

        while(right < n)
        {
            int maxchCount = 0;
            for(int i = 0;i < 26;i++)
            {
                maxchCount = max(maxchCount, chCount[i]);
            }
            if(right - left + 1 > maxchCount + k)
            {//左边的需要移动
                chCount[s[left]-'A']--;
                left++;
                maxlen = max(maxlen, right-left+1);
            }
            else
            {//右边的需要移动
                right++;
                if(right < n)
                    chCount[s[right]-'A']++;
            }
            maxlen = max(maxlen, right-left);
        }
        return maxlen;
    }
};
//https://leetcode.cn/problems/longest-repeating-character-replacement/