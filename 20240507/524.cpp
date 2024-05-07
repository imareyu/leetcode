class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ret = "";
        int n = dictionary.size();

        for(int i = 0;i < n;i++)
        {
            deque<char> dq(s.begin(), s.end());
            int j = 0;
            while(!dq.empty() && j < dictionary[i].size())
            {
                if(dq.front() == dictionary[i][j])
                {
                    j++;
                }
                dq.pop_front();
            }
            if(j == dictionary[i].size())
            {
                if(ret.size() < dictionary[i].size())
                {
                    ret = dictionary[i];
                }
                else
                {
                    if(ret.size() == dictionary[i].size())
                    {
                        ret = min(ret, dictionary[i]);
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/