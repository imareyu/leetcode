class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int,vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int mx = 0;

        while(!pq.empty())
        {
            if(pq.top() == 1)
            {
                pq.pop();
                mx = 1;
                continue;
            }
            if(pq.top() > mx)
            {
                mx++;
            }
            pq.pop();
        }
        return mx;
    }
};
//https://leetcode.cn/problems/maximum-element-after-decreasing-and-rearranging/