class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int jimin = 0;
        int oumin = 0;

        //偶数下标更小
        vector<int> nums1(nums.begin(), nums.end());
        for(int i = 0;i < n;i+=2)
        {
            if(i-1 >= 0&&nums1[i-1] >= nums1[i])
            {
                oumin += nums1[i-1] - nums1[i]+1;
                nums1[i-1] = nums1[i]-1;
            }
            if(i+1 < n&&nums1[i+1] >= nums1[i])
            {
                oumin += nums1[i+1] - nums1[i]+1;
                nums1[i+1] = nums1[i]-1;
            }
        }

        vector<int> nums2(nums.begin(), nums.end());
        for(int i = 1;i < n;i+=2)
        {
            if(i-1 >= 0&&nums2[i-1] >= nums2[i])
            {
                jimin += nums2[i-1] - nums2[i]+1;
                nums2[i-1] = nums2[i]-1;
            }
            if(i+1 < n&&nums2[i+1] >= nums2[i])
            {
                jimin += nums2[i+1] - nums2[i]+1;
                nums2[i+1] = nums2[i]-1;
            }
        }
        return min(oumin, jimin);
    }
};
//https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/description/