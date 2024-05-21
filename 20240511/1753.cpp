class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int mx = max(a, b);
        mx = max(mx, c);
        int sum = a+b+c;
        if(mx >= sum-mx)
            return sum-mx;
        return sum/2;
    }
};
//https://leetcode.cn/problems/maximum-score-from-removing-stones/description/