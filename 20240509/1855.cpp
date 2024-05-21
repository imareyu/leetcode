class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int j = 0;
        int ret = 0;

        for(int i = 0;i < n1;i++)
        {
            while(j < n2 && nums2[j] >= nums1[i])
            {
                j++;
            }
            j--;
            if(j < 0)
            {
                j = 0;
                continue;
            }
            ret = max(j-i, ret);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values/