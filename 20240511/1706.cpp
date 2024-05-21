class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ballPos;
        for(int i = 0;i < n;i++)
        {
            ballPos.emplace_back(i);
        }
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < ballPos.size();j++)
            {
                int pos = ballPos[j];
                if(pos == -1)
                {
                    continue;
                }
                if(grid[i][pos] == 1)
                {
                    if(pos+1 < n)
                    {
                        if(grid[i][pos+1] == 1)
                        {
                            ballPos[j]++;
                        }
                        else
                        {
                            ballPos[j] = -1;
                        }
                    }
                    else
                    {
                        ballPos[j] = -1;
                    }
                }
                else
                {
                    if(pos-1 >= 0)
                    {
                        if(grid[i][pos-1] == -1)
                        {
                            ballPos[j]--;
                        }
                        else
                        {
                            ballPos[j] = -1;
                        }
                    }
                    else
                    {
                        ballPos[j] = -1;
                    }
                }
            }
        }
        return ballPos;
    }
};
//https://leetcode.cn/problems/where-will-the-ball-fall/