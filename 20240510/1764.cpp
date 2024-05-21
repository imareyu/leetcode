class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int indexNums = 0;
        int i = 0;
        int j = 0;

        for(;i < n;i++)
        {
            for(j = 0;j < groups[i].size();j++)
            {
                if(indexNums+j >= nums.size())
                    break;
                if(groups[i][j] != nums[indexNums + j])
                {
                    j = -1;
                    indexNums++;
                }
            }
            if(j < groups[i].size())
            {
                return false;
            }
            if(j >= groups.size())
            {
                indexNums += j;
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/