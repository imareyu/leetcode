class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> data(query_row+1, vector<double>(query_row+1, 0.0));
        data[0][0] = poured;
        for(int i = 0;i < query_row;i++)
        {
            for(int j = 0;j <= i;j++)
            {
                if(data[i][j] > 1)
                {
                    double po = (data[i][j]-1)/2;
                    data[i+1][j] += po;
                    data[i+1][j+1] += po;
                }
            }
        }
        return data[query_row][query_glass]>1?1:data[query_row][query_glass];
    }
};
//https://leetcode.cn/problems/champagne-tower/