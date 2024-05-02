class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i = 0;i < n;i++)
        {
            int height = 0;
            int width = 0;

            for(int j = i;j >= 0;j--)
            {
                height = max(books[j][1], height);
                width += books[j][0];
                if(width > shelfWidth)
                    break;
                if(height + dp[j] < dp[i+1])
                {
                    dp[i+1] = height+dp[j];
                }
            }
        }
        return dp[n];
    }
};
//https://leetcode.cn/problems/filling-bookcase-shelves/description/