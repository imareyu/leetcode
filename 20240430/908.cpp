class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn = nums[0];
        int mx = nums[0];

        for(int i = 1;i < nums.size();i++)
        {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int ret = max(mx-mn-2*k, 0);
        return ret;
    }
};
//https://leetcode.cn/problems/smallest-range-i/