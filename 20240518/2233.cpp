class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0] + k;
        }
        sort(nums.begin(), nums.end());
        long long preSum = nums[0];
        long long ret = 1;

        int i = 1;
        for(;i < n;i++)
        {
            if((long long)i*nums[i]-preSum >= k)
            {
                break;
            }
            preSum += nums[i];
        }
        long long mx = (preSum+k)/i;//k=9   presum=15   len=3   35/3 = mx=12   12 2 12 
        for (int j = 0; j < i; j++)
        {
            int num = nums[j];
            nums[j] = mx;
            k -= nums[j]-num;
        }
        for (int j = 0; k > 0;j++,k--)
        {
            nums[j]++;
        }

        for(int num:nums)
        {
            ret = (ret*num)%1000000007;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/maximum-product-after-k-increments/description/