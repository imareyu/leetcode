class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0;i < m;i++)
        {
            vector<int> tempData;
            int x = i;
            int y = 0;
            while(x < m && y < n)
            {
                tempData.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tempData.begin(), tempData.end());
            x = i;
            y = 0;
            while(x < m && y < n)
            {
                mat[x][y] = tempData[y];
                x++;
                y++;
            }
        }
        for(int j = 1;j < n;j++)
        {
            vector<int> tempData;
            int x = 0;
            int y = j;
            while(x < m && y < n)
            {
                tempData.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tempData.begin(), tempData.end());
            x = 0;
            y = j;
            while(x < m && y < n)
            {
                mat[x][y] = tempData[x];
                x++;
                y++;
            }
        }
        return mat;
    }
};
//https://leetcode.cn/problems/sort-the-matrix-diagonally/description/