class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> yh(n, 0);
        yh[0] = nums[0];
        
        for(int i = 1;i < n;i++)
        {
            yh[i] = nums[i] ^ yh[i-1];
        }
        reverse(yh.begin(), yh.end());
        int res = pow(2, maximumBit) - 1;
        for(int i = 0;i < n;i++)
        {
            yh[i] = (yh[i] ^ res);
        }
        return yh;
    }
};
//https://leetcode.cn/problems/maximum-xor-for-each-query/