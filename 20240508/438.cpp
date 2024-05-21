class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};
        vector<int> phash(26, 0);
        int n = p.size();

        for(char ch:p)
        {
            phash[ch-'a']++;
        }
        vector<int> shash(26, 0);
        for(int i = 0;i < n;i++)
        {
            shash[s[i]-'a']++;
        }
        int left = 0;
        int right = n-1;
        vector<int> ret;

        while(right <= s.size())
        {
            bool notequal = false;
            for(int i = 0;i < 26;i++)
            {
                if(shash[i] != phash[i])
                {
                    notequal = true;
                    break;
                }
            }
            if(!notequal)
            {
                ret.emplace_back(left);
            }
            right++;
            if(right >= s.size())
            {
                break;
            }
            shash[s[right]-'a']++;
            shash[s[left]-'a']--;
            left++;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/find-all-anagrams-in-a-string/