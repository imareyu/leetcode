class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0;i < costs.size();i++)
        {
            pq.push(make_pair(costs[i][0] - costs[i][1], i));
        }
        int n = costs.size() / 2;
        int ret = 0;
        while(n > 0)
        {
            auto [_,index] = pq.top();
            pq.pop();
            ret += costs[index][0];
            n--;
        }
        while(!pq.empty())
        {
            auto [_,index] = pq.top();
            pq.pop();
            ret += costs[index][1];
        }
        return ret;
    }
};
//https://leetcode.cn/problems/two-city-scheduling/description/