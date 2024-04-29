class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = n-3;i >= 0;i--)
        {
            for(int j = n-2;j > i;j--)
            {
                for(int k = n-1;k > j;k--)
                {
                    if(nums[i] + nums[j] > nums[k])
                    {
                        ret = nums[i] + nums[j] + nums[k];
                        return ret;
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/largest-perimeter-triangle/description/