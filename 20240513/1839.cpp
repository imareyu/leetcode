class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int mxlen = 0;
        int n = word.size();
        map<char,int> indexs;
        indexs['a'] = 0;
        indexs['e'] = 1;
        indexs['i'] = 2;
        indexs['o'] = 3;
        indexs['u'] = 4;
        string sta;
        for(int i = 0;i < n;i++)
        {
            if(sta.empty())
            {
                if(word[i] == 'a')
                {
                    sta.push_back(word[i]);
                }
            }
            else
            {
                if(word[i] == sta.back() || indexs[word[i]] - indexs[sta.back()] == 1)
                {
                    sta.push_back(word[i]);
                }
                else
                {//不符合规则
                    if(sta.back() == 'u')
                    {
                        mxlen = max(mxlen, (int)sta.size());
                    }
                    sta.clear();
                    i--;
                }
            }
        }
        if(!sta.empty() && sta.back() == 'u')
        {
            mxlen = max(mxlen, (int)sta.size());
        }
        return mxlen;
    }
};
//https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/