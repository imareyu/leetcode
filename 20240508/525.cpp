class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp;
        int count0 = 0;
        int count1 = 0;
        int ret = 0;
        unordered_map<int, int> um;

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 1)
            {
                count1++;
            }
            else
            {
                count0++;
            }
            if(count0 == count1)
                ret = i + 1;
            dp.emplace_back(count0, count1);
            um[count0-count1] = i;
        }

        if(ret == n)
            return ret;
        for(int i = 0;i < n;i++)
        {
            if(n-i < ret)
                break;
            int subval = (dp[i].first - dp[i].second);
            //cout<<"subval="<<subval<<endl;
            if(um.count(subval) > 0)
                ret = max(ret, um[subval] - i);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/contiguous-array/