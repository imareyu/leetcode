class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int round = min(m/2, n/2);
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for(int i = 0;i < round;i++)
        {
            vector<int> data;
            int x = i;
            int y = i;
            for(;y < n-i;y++)
            {
                data.emplace_back(grid[x][y]);
            }
            y--;
            x++;
            for(;x < m-i;x++)
            {
                data.emplace_back(grid[x][y]);
            }
            x--;
            y--;
            for(;y >= i;y--)
            {
                data.emplace_back(grid[x][y]);
            }
            y++;
            x--;
            for(;x>i;x--)
            {
                data.emplace_back(grid[x][y]);
            }
            
            //计算偏移量，进行赋值
            int dataSize = data.size();
            int dis = k % dataSize;
            
            x = i;
            y = i;
            for(;y < n-i;y++)
            {
                ret[x][y] = data[dis];
                dis = (dis+1)%dataSize;
            }
            y--;
            x++;
            for(;x < m-i;x++)
            {
                ret[x][y] = data[dis];
                dis = (dis+1)%dataSize;
            }
            x--;
            y--;
            for(;y >= i;y--)
            {
                ret[x][y] = data[dis];
                dis = (dis+1)%dataSize;
            }
            y++;
            x--;
            for(;x>i;x--)
            {
                ret[x][y] = data[dis];
                dis = (dis+1)%dataSize;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/cyclically-rotating-a-grid/