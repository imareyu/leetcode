class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            int j = i;
            while(j < n-1)
            {
                if((long long)nums[j+1] - nums[j] == 1)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            if(j == i)
            {
                string tempStr = to_string(nums[i]);
                ret.emplace_back(tempStr);
                i++;
            }
            else
            {
                string tempStr = to_string(nums[i]) + "->" + to_string(nums[j]);
                ret.emplace_back(tempStr);
                i = j+1;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/summary-ranges/description/