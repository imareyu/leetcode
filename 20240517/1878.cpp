class Solution {
private:
    vector<int> ret;
    void insertVec(int num)
    {
        if(find(ret.begin(), ret.end(), num) == ret.end())
        {//没有出现的数字
            if(ret.size() < 3)//长度小于三，直接放进去
            {
                ret.emplace_back(num);
                sort(ret.begin(), ret.end(), greater<int>());
            }
            else
            {
                ret.emplace_back(num);
                sort(ret.begin(), ret.end(), greater<int>());
                ret.pop_back();
            }
        }
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        ret.clear();

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                insertVec(grid[i][j]);
                int dis = 1;
                while(true)
                {
                    if(i + dis*2 >= m || j-dis < 0 || j+dis >= n)
                    {
                        break;
                    }
                    int sum = grid[i][j] + grid[i+dis*2][j] + grid[i+dis][j-dis] + grid[i+dis][j+dis];
                    for(int d = 1;d < dis;d++)//左上
                    {
                        sum += grid[i+d][j-d];
                    }
                    for(int d = 1;d < dis;d++)//右上
                    {
                        sum += grid[i+d][j+d];
                    }
                    for(int d = 1;d < dis;d++)//左下
                    {
                        sum += grid[i+dis+d][j-dis+d];
                    }
                    for(int d = 1;d < dis;d++)//右下
                    {
                        sum += grid[i+dis+d][j+dis-d];
                    }
                    insertVec(sum);
                    dis++;
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid/