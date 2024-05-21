class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long mn = 0;
        long long mx = 0;
        long long pre = 0;
        for(int i = 0;i < n;i++)
        {
            pre += differences[i];
            mx = max(pre, mx);
            mn = min(pre, mn);
        }
        long long start = lower - mn;//lower = 10  -6
        long long end = upper - mx;//upper 100  60
        if(start <= end)
        {
            return end-start+1;
        }
        return 0;
    }
};
//https://leetcode.cn/problems/count-the-hidden-sequences/