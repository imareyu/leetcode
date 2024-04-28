class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, 0);
        for(int j = 0;j < n;j++)
        {
            int mx = 0;
            for(int i = 0;i < m;i++)
            {
                int num = grid[i][j];
                int length = 0;
                if(num <= 0)
                {
                    length = 1;
                    num = -num;
                }
                while(num > 0)
                {
                    length++;
                    num = num/10;
                }
                mx = max(mx, length);
            }
            ans[j] = mx;
        }
        return ans;
    }
};
//https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/?envType=daily-question