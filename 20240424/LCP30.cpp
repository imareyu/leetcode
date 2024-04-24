class Solution {
public:
    int magicTower(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>> data;//小顶堆
        int n = nums.size();
        long long blood = 1;
        long long needsub = 0;
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] < 0)
            {
                data.push(nums[i]);
            }

            blood += nums[i];
            if(blood <= 0)
            {
                int minx = data.top();
                data.pop();
                blood += -minx;
                needsub += minx;
                count++;
            }
        }
        if(blood + needsub <= 0)
            return -1;
        return count;
    }
};
//https://leetcode.cn/problems/p0NxJO/description/?envType=daily-question