class Solution {
private:
    int m = 0;
    int n = 0;
    bool check(deque<pair<int,int>>& node, vector<vector<int>>& grid)
    {
        int ret = true;//true为岛，false不是岛
        while(!node.empty())
        {
            auto [x,y] = node.front();
            node.pop_front();
            grid[x][y] = 2;
            if(x == 0 || x == m-1 || y == 0 || y == n-1)
                ret = false;
            if(x-1 >= 0)
            {//上
                if(grid[x-1][y] == 0)
                {
                    grid[x-1][y] = 2;
                    node.push_back(make_pair(x-1, y));
                }
            }
            if(y-1 >= 0)
            {//左
                if(grid[x][y-1] == 0)
                {
                    grid[x][y-1] = 2;
                    node.push_back(make_pair(x, y-1));
                }
            }
            if(y+1 < n)
            {//右
                if(grid[x][y+1] == 0)
                {
                    grid[x][y+1] = 2;
                    node.push_back(make_pair(x, y+1));
                }
            }
            if(x+1 < m)
            {//上
                if(grid[x+1][y] == 0)
                {
                    grid[x+1][y] = 2;
                    node.push_back(make_pair(x+1, y));
                }
            }
        }
        return ret;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        //访问过改成2
        m = grid.size();
        n = grid[0].size();
        int ret = 0;

        for(int i = 1;i < m-1;i++)
        {
            for(int j = 1;j < n-1;j++)
            {
                if(grid[i][j] == 0)
                {
                    deque<pair<int,int>> node;
                    node.push_back(make_pair(i, j));
                    bool result = check(node, grid);
                    if(result)
                        ret++;
                }
            }
        }

        return ret;
    }
};
//https://leetcode.cn/problems/number-of-closed-islands/description/