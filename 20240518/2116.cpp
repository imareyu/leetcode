class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n%2 == 1)
        {
            return false;
        }
        
        int leftlock = 0;//(
        int rightlock = 0;//)
        for(int i = 0;i < n;i++)
        {
            if(locked[i] == '1')
            {
                if(s[i] == ')')
                {
                    rightlock++;
                }
                if(rightlock*2 > i+1)
                {
                    return false;
                }
            }
        }

        for(int i = n-1;i >= 0;i--)
        {
            if(locked[i] == '1')
            {
                if(s[i] == '(')
                {
                    leftlock++;
                }
                if(leftlock*2 > n-i)
                {
                    return false;
                }
            }
        }

        return true;
    }
};
//https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid/