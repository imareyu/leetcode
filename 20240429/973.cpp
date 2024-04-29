class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;//小顶堆
        for(int i = 0;i < points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            pq.push(make_tuple(dis, x, y));
        }
        vector<vector<int>> ret;
        while(k > 0 && !pq.empty())
        {
            auto [dis,x,y] = pq.top();
            pq.pop();
            ret.emplace_back(vector<int>{x,y});
            k--;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/k-closest-points-to-origin/description/