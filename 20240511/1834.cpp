class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i = 0;i < n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int index = 0;
        long long time = 0;
        vector<int> ret;
        while(!pq.empty() || index < n)
        {
            if(pq.empty())
            {
                time = max(time,(long long)tasks[index][0]);
            }
            for(;index < n;index++)
            {
                if(tasks[index][0] <= time)
                {
                    pq.push(make_pair(tasks[index][1], tasks[index][2]));
                }
                else
                    break;
            }
            auto [exetime, yin] = pq.top();
            pq.pop();
            ret.emplace_back(yin);
            time += exetime;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/single-threaded-cpu/