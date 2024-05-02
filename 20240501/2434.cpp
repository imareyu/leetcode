class Solution {
public:
    string robotWithString(string s) {
        vector<int> chCount(26,0);

        for(char ch:s)
        {
            chCount[ch-'a']++;
        }
        int index = 0;
        while(index < 26 && chCount[index] == 0)
        {
            index++;
        }
        stack<char> sta;
        string ret;
        for(int i = 0;i < s.size();i++)
        {
            if(sta.empty())
            {
                sta.push(s[i]);
                chCount[s[i]-'a']--;
                continue;
            }
            char ctop = sta.top();
            int index = 0;
            while(index < 26 && chCount[index] == 0)
            {
                index++;
            }
            if(index == 26)
            {
                break;
            }
            if((int)(ctop-'a') <= index)
            {
                ret += ctop;
                sta.pop();
                i--;
            }
            else
            {
                sta.push(s[i]);
                chCount[s[i]-'a']--;
            }
        }
        while(!sta.empty())
        {
            ret += sta.top();
            sta.pop();
        }
        return ret;
    }
};
//https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/