class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str = "";
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] != '-')
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    str += (char)(s[i]-32);
                }
                else
                    str += s[i];
            }
        }
        string ret;
        int i = 0;
        for(;i < min(k, (int)(str.size())%k);i++)
            ret += str[i];
        cout<<ret;
        for(;i < str.size();)
        {
            if(ret.size())
                ret += "-";
            int count = k;
            while(count)
            {
                ret += str[i];
                i++;
                count--;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/license-key-formatting/