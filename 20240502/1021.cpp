class Solution {
public:
    string removeOuterParentheses(string s) {
        //vector<string> data;

        stack<char> sta;
        int i = 0;
        int n = s.size();
        string ret = "";
        string str = "";

        while(i < n)
        {
            str += s[i];
            if(sta.empty())
            {
                sta.push(s[i]);
            }
            else
            {
                if(s[i] == ')')
                {
                    sta.pop();
                    if(sta.empty())
                    {
                        str.erase(str.end()-1);
                        str.erase(str.begin());
                        ret += str;
                        str = "";
                    }
                }
                else
                {
                    sta.push(s[i]);
                }
            }
            i++;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/remove-outermost-parentheses/description/