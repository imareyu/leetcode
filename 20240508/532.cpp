class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> data;

        for(int num:nums)
        {
            data[num]++;
        }

        int ret = 0;
        for(auto [val,count] : data)
        {
            if(k == 0)
            {
                if(count > 1)
                {
                    ret++;
                }
            }
            else
            {
                int findval = val + k;
                if(data.count(findval) > 0)
                {
                    ret++;
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/k-diff-pairs-in-an-array/