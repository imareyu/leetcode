class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        map<int, int> valCount;
        valCount[0] = 1;

        for(int i = 0;i < n;i++)
        {
            map<int,int> newValCount;
            for(auto [val, count]:valCount)
            {
                if(val + sum >= target)
                {
                    newValCount[val+nums[i]] += count;
                }
                if(val - sum <= target)
                {
                    newValCount[val-nums[i]] += count;
                }
            }
            sum -= nums[i];
            valCount = newValCount;
        }
        return valCount[target];
    }
};
//https://leetcode.cn/problems/target-sum/