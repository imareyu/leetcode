class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<string> sdata;
        int n = s.size();
        int i = 0;
        int ret = 0;

        while(i < n)
        {
            int j = i+1;
            while(j < n && s[j] == s[i])
            {
                j++;
            }
            sdata.emplace_back(string(j-i, s[i]));
            i = j;
        }
        for(string word:words)
        {
            int index = 0;
            int j = 0;
            while(j < word.size())
            {
                int k = j+1;
                while(k < word.size() && word[k] == word[j])
                {
                    k++;
                }
                if(word[j] == sdata[index][0])
                {
                    if(k-j > sdata[index].size() || (k-j < sdata[index].size() && sdata[index].size() < 3))//匹配失败的情况
                    {
                        break;
                    }
                }
                else//字母不相等，不可能匹配成功
                {
                    break;
                }
                j = k;
                index++;
                if(index >= sdata.size())
                    break;
            }
            if(j >= word.size()&&index >= sdata.size())
            {
                ret++;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/expressive-words/description/