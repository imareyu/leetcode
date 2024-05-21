class Solution {
public:
    int minSwaps(string s) {
        stack<char> sta;

        for(char ch:s)
        {
            if(sta.empty())
            {
                sta.push(ch);
            }
            else
            {
                if(sta.top() == ']')
                {
                    sta.push(ch);
                }
                else//[
                {
                    if(ch == ']')
                    {
                        sta.pop();
                    }
                    else
                    {
                        sta.push(ch);
                    }
                }
            }
        }
        if(sta.empty())
            return 0;
        int ret = 0;
        ret = (sta.size()+3)/4;
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/