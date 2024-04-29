class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> newNums;
        for(int i = 0;i < nums.size();i++)
        {
            newNums.emplace_back(nums[i], i);
        }
        sort(newNums.begin(), newNums.end());
        //stack<int> sta;
        int mn = newNums[0].second;
        int ret = 0;
        for(int i = 1;i < newNums.size();i++)
        {
            if(newNums[i].second > mn)
            {
                ret = max(ret, newNums[i].second - mn);
            }
            else
            {
                mn = newNums[i].second;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/maximum-width-ramp/description/