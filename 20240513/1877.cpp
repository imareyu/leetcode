class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        int n = nums.size();
        for(int i = 0;i < n/2;i++)
        {
            ret = max(ret, nums[i]+nums[n-1-i]);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array/