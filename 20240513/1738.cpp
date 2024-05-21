class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> rowyh(m, vector<int>(n, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i = 0;i < m;i++)
        {
            rowyh[i][0] = matrix[i][0];
            for(int j = 1;j < n;j++)
            {
                rowyh[i][j] = rowyh[i][j-1] ^ matrix[i][j];
            }
        }
        vector<int> data;
        for(int j = 0;j < n;j++)
        {
            res[0][j] = rowyh[0][j];
            data.emplace_back(res[0][j]);
            for(int i = 1;i < m;i++)
            {
                res[i][j] = rowyh[i][j] ^ res[i-1][j];
                data.emplace_back(res[i][j]);
            }
        }
        sort(data.begin(), data.end());
        return data[data.size()-k];
    }
};
//https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/