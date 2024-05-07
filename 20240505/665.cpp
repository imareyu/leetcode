class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int change = false;

        for(int i = 0;i < n-1;i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(change)
                    return false;
                if(i-1 >= 0 && nums[i-1] > nums[i+1] && i+2<n && nums[i] > nums[i+2])
                {
                    return false;
                }
                change = true;
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/non-decreasing-array/description/