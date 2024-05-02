class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);
        vector<int> zerosRow(m, 0);
        vector<int> zerosCol(n, 0);
        vector<vector<int>> ret(m, vector<int>(n, 0));

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 0)
                {
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
                else
                {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                ret[i][j] = onesRow[i]+onesCol[j]-zerosRow[i]-zerosCol[j];
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/difference-between-ones-and-zeros-in-row-and-column/description/