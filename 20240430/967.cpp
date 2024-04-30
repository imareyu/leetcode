class Solution {
    void dfs(int num,int len,vector<int>& ret,int absval,int maxlen)
    {
        if(maxlen == len)
        {
            ret.emplace_back(num);
            return;
        }
        int lastNum = num % 10;
        int sma = lastNum - absval;
        if(sma >= 0)
        {
            dfs(num*10+sma,len+1,ret,absval,maxlen);
        }
        int big = lastNum+absval;
        if(big == sma||big >= 10)
            return;
        dfs(num*10+big,len+1,ret,absval,maxlen);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ret;
        for(int i = 1;i < 10;i++)
        {
            dfs(i,1,ret,k,n);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/numbers-with-same-consecutive-differences/description/