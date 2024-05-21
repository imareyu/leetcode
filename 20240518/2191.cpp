class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> sorted;

        for(int i = 0;i < n;i++)
        {
            int num = nums[i];
            vector<int> data;
            if(num == 0)
            {
                data.emplace_back(mapping[num]);
            }

            while(num > 0)
            {
                int yu = num%10;
                data.emplace_back(mapping[yu]);
                num = num/10;
            }
            int newNum = 0;
            for(int j = data.size()-1;j >= 0;j--)
            {
                newNum = newNum*10 + data[j];
            }
            sorted.emplace_back(newNum, i);
        }
        sort(sorted.begin(), sorted.end());
        vector<int> ret(n, 0);
        for(int i = 0;i < n;i++)
        {
            ret[i] = nums[sorted[i].second];
        }
        return ret;
    }
};
//https://leetcode.cn/problems/sort-the-jumbled-numbers/description/