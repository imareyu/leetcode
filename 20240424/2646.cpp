class Solution {
private:
    bool dfs(vector<int>& road,int to,vector<vector<int>>& tree)
    {
        int from = road[road.size()-1];
        if(from == to)
        {
            return true;
        }
        bool ret = true;
        for(int i = 0;i < tree[from].size();i++)
        {
            if(find(road.begin(), road.end(), tree[from][i]) == road.end())//不在路径上
            {
                road.push_back(tree[from][i]);
                ret = dfs(road, to, tree);
                if(ret)
                {
                    return true;
                }
                road.pop_back();
            }
        }
        return false;
    }
    pair<int,int> dfs2(int node,int parent,vector<int>& price, vector<int> count,vector<vector<int>>& tree)
    {
        pair<int,int> ret = {price[node]*count[node],price[node]*count[node]/2};
        for(int child:tree[node])
        {
            if(child != parent)
            {
                auto [x,y] = dfs2(child,node,price,count,tree);
                ret.first += min(x,y);
                ret.second += x;
            }
        }
        return ret;
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> tree(n);
        vector<int> count(n, 0);
        int beforeHalf = 0;
        for(int i =0;i < edges.size();i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        for(int i = 0;i < trips.size();i++)
        {
            int from = trips[i][0];
            int to = trips[i][1];
            vector<int> road;
            road.push_back(from);
            dfs(road, to, tree);
            for(auto r:road)
            {
                count[r]++;
            }
        }

        //接下来dp
        auto [x,y] = dfs2(0, -1, price,count,tree);
        return min(x,y);
    }
};
//https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/description/