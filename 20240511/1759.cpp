class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1000000007;
        int n = s.size();

        int i = 0;
        long long ret = 0;
        while(i < n)
        {
            int j = i+1;
            for(;j < n;j++)
            {
                if(s[j] != s[i])
                    break;
            }
            long long len = j-i;
            ret = (ret + len*(len+1)/2)%mod;
            i = j;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/count-number-of-homogenous-substrings/