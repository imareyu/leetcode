class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> count1(m+1, vector<pair<int,int>>(n+1,pair<int,int>(0,0)));

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 1)
                {
                    count1[i+1][j+1].first = count1[i][j+1].first+1;//first记录上
                    count1[i+1][j+1].second = count1[i+1][j].second+1;//second记录左边
                    //cout<<i<<j<<" "<<count1[i+1][j+1].first;
                }
                else
                {
                    count1[i+1][j+1].first = 0;//first记录上
                    count1[i+1][j+1].second = 0;//second记录左边
                }
            }
        }
        for(int i = m;i > ret;i--)
        {
            for(int j = n;j > ret;j--)
            {
                if(count1[i][j].first == 0)
                {
                    continue;
                }
                ret = max(ret, 1);
                int len = min(count1[i][j].first, count1[i][j].second)-1;
                //cout<<i<<" "<<j<<" "<<len<<endl;
                for(;len > 0;len--)
                {
                    //cout<<count1[i-len][j].second<<" "<<count1[i][j-len].first<<endl;
                    if(count1[i-len][j].second > len && count1[i][j-len].first > len)
                    {
                        break;
                    }
                }
                ret = max(ret, len+1);
            }
        }
        ret = ret*ret;
        return ret;
    }
};
//https://leetcode.cn/problems/largest-1-bordered-square/description/