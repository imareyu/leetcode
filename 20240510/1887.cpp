class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;

        for(int num:nums)
        {
            mp[num]++;
        }

        int ret = 0;
        auto it = mp.begin();
        it++;
        int index = 1;
        for(;it != mp.end();it++,index++)
        {
            auto [val,count] = *it;
            ret += index*count;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/reduction-operations-to-make-the-array-elements-equal/