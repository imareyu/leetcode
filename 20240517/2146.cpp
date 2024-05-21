class Solution {
private:
    vector<vector<int>> ret;
    int k = 0;
    vector<pair<int,int>> direc = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void insertRet(int& step, int price, int& x, int& y)
    {
        vector<int> temp = {step, price, x, y};
        ret.emplace_back(temp);
        if(ret.size() > k)
        {
            sort(ret.begin(), ret.end());
            while(ret.size() > k)
            {
                ret.pop_back();
            }
        }
    }
    void bfs(deque<pair<int,int>>& dq, vector<vector<int>>& grid, vector<int>& pricing)
    {
        int m = grid.size();
        int n = grid[0].size();
        int step = 0;
        while(!dq.empty())
        {
            int dqSize = dq.size();
            for(int i = 0;i < dqSize;i++)
            {
                auto [x,y] = dq.front();
                dq.pop_front();
                if(grid[x][y] > 1 && grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1])
                {
                    insertRet(step, grid[x][y], x, y);
                    step++;
                }
                grid[x][y] = 0;
                for(auto [xadd,yadd] : direc)
                {
                    int x1 = x+xadd;
                    int y1 = y+yadd;

                    if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] > 0)
                    {
                        dq.emplace_back(x1, y1);
                        if(grid[x1][y1] > 1 && grid[x1][y1] >= pricing[0] && grid[x1][y1] <= pricing[1])
                        {
                            insertRet(step, grid[x1][y1], x1, y1);
                        }
                        grid[x1][y1] = 0;
                    }
                }
            }
            step++;
        }
    }
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        ret.clear();
        int m = grid.size();
        int n = grid[0].size();
        this->k = k;

        deque<pair<int,int>> dq;
        dq.emplace_back(start[0], start[1]);
        bfs(dq, grid, pricing);
        vector<vector<int>> realret;
        sort(ret.begin(), ret.end());
        for(auto& vec:ret)
        {
            vector<int> tempVec = {vec[2], vec[3]};
            realret.emplace_back(tempVec);
        }
        return realret;
    }
};
//https://leetcode.cn/problems/k-highest-ranked-items-within-a-price-range/description/