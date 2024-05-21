class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(numCarpets+1, vector<int>(n, 0));
        vector<int> presum(n, 0);
        presum[0] = floor[0] == '1' ? 1:0;
        int mxCover = 0;

        for(int i = 1;i < n;i++)
        {
            presum[i] = presum[i-1];
            presum[i] += (floor[i] == '1' ? 1:0);
        }

        for(int j = 0;j < n;j++)
        {
            for(int i = 1;i <= numCarpets;i++)
            {
                if(i*carpetLen >= j+1)
                {
                    dp[i][j] = presum[j];
                    mxCover = max(mxCover, dp[i][j]);
                    continue;
                }
                int mx = 0;
                int k = max((i-1)*carpetLen-1, 0);
                for(;k <= j-carpetLen;k++)
                {
                    mx = max(dp[i-1][k], mx);
                    if(mx >= (i-1)*carpetLen)
                    {
                        break;
                    }
                }
                dp[i][j] = max(mx-presum[j-carpetLen]+presum[j], 0);
                mxCover = max(mxCover, dp[i][j]);
            }
        }
        return presum[n-1]- mxCover;
    }
};
//https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/