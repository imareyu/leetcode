class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mnIndex = min_element(nums.begin(), nums.end())- nums.begin();
        int mxIndex = max_element(nums.begin(), nums.end())- nums.begin();
        int n = nums.size();
        if(mnIndex == mxIndex)
        {
            return 1;   
        }
        if(mnIndex > mxIndex)
        {
            swap(mnIndex, mxIndex);
        }
        int ret = max(mnIndex, n-mxIndex-1);
        ret = max(ret, mxIndex- mnIndex-1);
        return n-ret;
    }
};
//https://leetcode.cn/problems/removing-minimum-and-maximum-from-array/