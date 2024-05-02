class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        int sum = n*(n+1)/2;
        int num = 1;
        while(num < n)
        {
            int sum1 = num*(num+1)/2;
            int sum2 = sum - sum1 + num;
            if(sum1 == sum2)
            {
                return num;
            }
            if(sum1 > sum2)
                break;
            num++;
        }
        return -1;
    }
};
//https://leetcode.cn/problems/find-the-pivot-integer/