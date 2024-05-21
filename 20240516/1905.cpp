class Solution {
private:
    vector<pair<int, int>> direc = {{-1,0},{1,0},{0,-1},{0,1}};
    bool findLands(vector<vector<int>>& grid1, deque<pair<int, int>>& dq, vector<vector<int>>& grid)
    {
        bool ret = true;
        int m = grid1.size();
        int n = grid1[0].size();
        while(!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();
            grid1[x][y] = 0;
            for(auto& dire:direc)
            {
                int x1 = x+dire.first;
                int y1 = y+dire.second;
                
                if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid1[x1][y1] == 1)
                {
                    if(grid[x1][y1] == 0)
                    {
                        ret = false;
                    }
                    grid1[x1][y1] = 0;
                    dq.emplace_back(x1, y1);
                }
            }
        }
        return ret;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        int ret = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid2[i][j] == 1 && grid1[i][j] != 0)
                {
                    deque<pair<int,int>> dq;
                    dq.emplace_back(i, j);
                    if(findLands(grid2, dq, grid1))
                    {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/count-sub-islands/