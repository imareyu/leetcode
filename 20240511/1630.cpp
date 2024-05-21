class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();;
        int m = l.size();
        vector<bool> ret(m, false);
        for(int i = 0;i < m;i++)
        {
            int left = l[i];
            int right = r[i];
            if(left+1 == right)
            {
                ret[i] = true;
            }
            priority_queue<int, vector<int>, greater<int>> pq(nums.begin()+left, nums.begin()+right+1);//最小数字
            int mn = pq.top();
            pq.pop();
            int nowval = pq.top();
            pq.pop();
            int dis = nowval - mn;
            bool res = true;
            while(!pq.empty())
            {
                int val = pq.top();
                pq.pop();
                if(val - nowval != dis)
                {
                    res = false;
                    break;
                }
                nowval = val;
            }
            ret[i] = res;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/arithmetic-subarrays/