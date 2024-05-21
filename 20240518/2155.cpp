class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int sum = -1;
        vector<int> ret;

        for(int i = 0;i < n;i++)
        {
            count1 += nums[i];
        }

        sum = count1;
        ret.emplace_back(0);
        int leftCount0 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(nums[i-1] == 1)
            {
                count1--;
            }
            else
            {
                leftCount0++;
            }
            if(leftCount0 + count1 > sum)
            {
                sum = leftCount0 + count1;
                ret.clear();
                ret.emplace_back(i);
            }
            else
            {
                if(leftCount0 + count1 == sum)
                {
                    ret.emplace_back(i);
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/