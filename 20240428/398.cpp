class Solution {
private:
    map<int,vector<int>> data;
public:
    Solution(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++)
        {
            data[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int vecSize = data[target].size();
        //srand(time(0));
        int randNum = rand();
        randNum = randNum%(vecSize);
        return data[target][randNum];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
//https://leetcode.cn/problems/random-pick-index/