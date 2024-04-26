class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> next(n);

        for(int i = 0;i < roads.size();i++)
        {
            int from = roads[i][0];
            int to = roads[i][1];
            int w = roads[i][2];
            next[from].emplace_back(to,w);
            next[to].emplace_back(from,w);
        }
        vector<long long> dis(n,LLONG_MAX);
        dis[0] = 0;
        priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push(make_pair(0, 0));
        vector<long long> ways(n, 0);
        ways[0] = 1;
        while(!pq.empty())
        {
            auto[distance,node] = pq.top();
            pq.pop();
            if(distance > dis[node])
                continue;

            for(auto [to,w]:next[node])
            {
                if(dis[to] > w + distance)
                {
                    dis[to] = w+ distance;
                    pq.push(make_pair(w+ distance, to));
                    ways[to] = ways[node];
                }
                else
                {
                    if(dis[to] == w + distance)
                    {
                        ways[to] = (ways[to] + ways[node])%1000000007;
                    }
                }
            }
        }
        return ways[n-1];

    }
};
//https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/description/?envType=daily-question