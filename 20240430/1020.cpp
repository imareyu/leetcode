class Solution {
private:
    void dfs(vector<vector<int>>& grid, deque<pair<int,int>> dq)
    {
        while(!dq.empty())
        {
            auto [x,y] = dq.front();
            dq.pop_front();
            grid[x][y] = 2;
            if(x-1 >= 0 && grid[x-1][y] == 1)
            {
                dq.push_back(make_pair(x-1, y));
                grid[x-1][y] = 2;
            }
            if(y-1 >= 0 && grid[x][y-1] == 1)
            {
                dq.push_back(make_pair(x, y-1));
                grid[x][y-1] = 2;
            }
            if(x+1 < grid.size() && grid[x+1][y] == 1)
            {
                dq.push_back(make_pair(x+1, y));
                grid[x+1][y] = 2;
            }
            if(y+1 < grid[0].size() && grid[x][y+1] == 1)
            {
                dq.push_back(make_pair(x, y+1));
                grid[x][y+1] = 2;
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //把四个边缘的1和连接的全部变成2
        int m = grid.size();
        int n = grid[0].size();

        for(int j = 0;j < n;j++)//第0行
        {
            if(grid[0][j] == 1)
            {
                deque<pair<int,int>> dq;
                dq.push_back(make_pair(0,j));
                dfs(grid, dq);
            }
        }
        for(int j = 0;j < n;j++)//第0行
        {
            if(grid[m-1][j] == 1)
            {
                deque<pair<int,int>> dq;
                dq.push_back(make_pair(m-1,j));
                dfs(grid, dq);
            }
        }
        for(int i = 0;i < m;i++)//第0行
        {
            if(grid[i][0] == 1)
            {
                deque<pair<int,int>> dq;
                dq.push_back(make_pair(i,0));
                dfs(grid, dq);
            }
        }
        for(int i = 0;i < m;i++)//第0行
        {
            if(grid[i][n-1] == 1)
            {
                deque<pair<int,int>> dq;
                dq.push_back(make_pair(i,n-1));
                dfs(grid, dq);
            }
        }
        int ret = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 1)
                    ret++;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/number-of-enclaves/description/