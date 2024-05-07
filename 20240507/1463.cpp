class Solution {
private:
    vector<pair<int,int>> nextposition = {{-1,-1},{-1,0},{-1,1}, {0,-1},{0,0},{0,1}, {1,-1},{1,0},{1,1}};
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n, INT_MIN)));
        int ret = 0;
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        ret = dp[0][0][n-1];
        for(int i = 0;i < m-1;i++)
        {
            for(int j = 0;j < n;j++)
            {
                for(int k = 0;k < n;k++)
                {
                    if(k == j)
                        continue;
//                    cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
                    if(dp[i][j][k] != INT_MIN)
                    {
//                        cout<<dp[i][j][k]<<endl;
                        int nextrow = i+1;
                        int y1 = j;
                        int y2 = k;
                        for(auto [p1,p2]:nextposition)
                        {
                            if(y1+p1 != y2+p2 && y1+p1 >= 0 && y1+p1 <n && y2+p2 >= 0 && y2+p2 < n)
                            {
                                dp[nextrow][y1+p1][y2+p2] = max(dp[i][j][k] + grid[nextrow][y1+p1] + grid[nextrow][y2+p2],dp[nextrow][y1+p1][y2+p2]);
                                ret = max(ret, dp[nextrow][y1+p1][y2+p2]);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/cherry-pickup-ii/description/