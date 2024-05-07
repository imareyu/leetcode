class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] < 0&&k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
            else
            {
                break;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(k % 2 == 0)
            return sum;
        int minnum = *min_element(nums.begin(), nums.end());
        sum -= minnum*2;
        return sum;
    }
};
//https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/