class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> count1(32, 0);
        int n = nums.size();

        for(int i = 0;i < n;i++)
        {
            int num = nums[i];
            int j = 0;
            while(num)
            {
                int c = num % 2;
                if(c)
                {
                    count1[j]++;
                }
                j++;
                num = num/2;
            }
        }
        int ret = 0;
        for(int i = 0;i < 32;i++)
        {
            ret += (n - count1[i]) * count1[i];
        }
        return ret;
    }
};
//https://leetcode.cn/problems/total-hamming-distance/description/