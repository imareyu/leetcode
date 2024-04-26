class Solution {
private:
    int n = 0;
public:
    int minimumSeconds(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, vector<int>> data;
        if(n == 1)
        {
            return 0;
        }

        int ret = INT_MAX;
        for(int i = 0;i < n;i++)
        {
            data[nums[i]].push_back(i);
        }
        for(auto it = data.begin();it != data.end();it++)
        {
            int distance = 0;
            int num = (*it).first;
            for(int i = 1;i < data[num].size();i++)
            {
                    distance = max(data[num][i] - data[num][i-1], distance);
            }
            int e = n - (data[num][data[num].size()-1]-data[num][0]);
            distance = max(e, distance);
            int costtime = distance / 2;//1 0 2 1 3 1 4 2 5 2
            ret = min(ret, costtime);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/description/?envType=daily-question