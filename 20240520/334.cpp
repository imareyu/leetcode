class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<bool> before(n, false);

        int mn = nums[0];

        for(int i = 0;i < n;i++)
        {
            if(nums[i] > mn)
            {
                before[i] = true;
            }
            else
            {
                mn = nums[i];
            }
        }
        int mx = nums[n-1];
        for(int i = n-2;i > 0;i--)
        {
            if(before[i] && mx > nums[i])
            {
                return true;
            }
            mx = max(mx, nums[i]);
        }
        return false;
    }
};
//https://leetcode.cn/problems/increasing-triplet-subsequence/