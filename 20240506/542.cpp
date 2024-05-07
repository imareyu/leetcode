class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        set<pair<int,int>> untouch1;
        set<pair<int,int>> nearest;
        int dis = 1;

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(mat[i][j] == 1)
                {
                    untouch1.insert(make_pair(i, j));
                }
                else
                {//0，判断下有没有相邻的1
                    if(i-1 >= 0 && mat[i-1][j] == 1)
                    {
                        nearest.insert(make_pair(i, j));
                        continue;
                    }
                    if(i+1 < m && mat[i+1][j] == 1)
                    {
                        nearest.insert(make_pair(i, j));
                        continue;
                    }
                    if(j-1 >= 0 && mat[i][j-1] == 1)
                    {
                        nearest.insert(make_pair(i, j));
                        continue;
                    }
                    if(j+1 < n && mat[i][j+1] == 1)
                    {
                        nearest.insert(make_pair(i, j));
                        continue;
                    }
                }
            }
        }
        while(!untouch1.empty())
        {
            set<pair<int,int>> tempset;
            for(auto [i,j] : nearest)
            {
                if(i-1 >= 0 && mat[i-1][j] == 1 && ret[i-1][j] == 0)
                {
                    ret[i-1][j] = dis;
                    untouch1.erase(make_pair(i-1,j));
                    tempset.insert(make_pair(i-1,j));
                }
                if(i+1 < m && mat[i+1][j] == 1 && ret[i+1][j] == 0)
                {
                    ret[i+1][j] = dis;
                    untouch1.erase(make_pair(i+1,j));
                    tempset.insert(make_pair(i+1,j));
                }
                if(j-1 >= 0 && mat[i][j-1] == 1&& ret[i][j-1] == 0)
                {
                    ret[i][j-1] = dis;
                    untouch1.erase(make_pair(i,j-1));
                    tempset.insert(make_pair(i,j-1));
                }
                if(j+1 < n && mat[i][j+1] == 1&& ret[i][j+1] == 0)
                {
                    ret[i][j+1] = dis;
                    untouch1.erase(make_pair(i,j+1));
                    tempset.insert(make_pair(i,j+1));
                }
            }
            dis++;
            nearest = tempset;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/01-matrix/