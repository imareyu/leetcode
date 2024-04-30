class Solution {
private:
    void dfs(deque<pair<int,int>>& dq,vector<string>& newgrid)
    {
        while(!dq.empty())
        {
            auto [i,j] = dq.front();
            dq.pop_front();
            newgrid[i][j] = '1';
            int m = newgrid.size();
            int n = newgrid[0].size();
            if(i+1 < m && newgrid[i+1][j] == '0')
            {
                dq.push_back(make_pair(i+1,j));
                newgrid[i+1][j] = '1';
            }
            if(i-1 >= 0 && newgrid[i-1][j] == '0')
            {
                dq.push_back(make_pair(i-1,j));
                newgrid[i-1][j] = '1';
            }
            if(j+1 < n && newgrid[i][j+1] == '0')
            {
                dq.push_back(make_pair(i,j+1));
                newgrid[i][j+1] = '1';
            }
            if(j-1 >= 0 && newgrid[i][j-1] == '0')
            {
                dq.push_back(make_pair(i,j-1));
                newgrid[i][j-1] = '1';
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = m;

        vector<string> newgrid(m*3,string(n*3,'0'));

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == ' ')
                {
                    continue;
                }
                int x = i*3;
                int y = j*3;
                if(grid[i][j] == '/')
                {
                    newgrid[x][y+2] = '1';
                    newgrid[x+1][y+1] = '1';
                    newgrid[x+2][y] = '1';
                }
                else
                {
                    newgrid[x][y] = '1';
                    newgrid[x+1][y+1] = '1';
                    newgrid[x+2][y+2] = '1';
                }
            }
        }
        /*
        for(int i = 0;i < m*3;i++)
        {
            for(int j = 0;j < n*3;j++)
            {
                cout<<newgrid[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int ret = 0;
        for(int i = 0;i < m*3;i++)
        {
            for(int j = 0;j < n*3;j++)
            {
                if(newgrid[i][j] == '0')
                {
                    deque<pair<int,int>> dq;
                    dq.push_back(make_pair(i, j));
                    dfs(dq,newgrid);
                    ret++;
                }
            }
        }
        return ret;
    }
};
/*
//
/ 
001001
010010
100100
001000
010000
100000

/\
\/

001100
010010
100001
100001
010010
001100

*/
//https://leetcode.cn/problems/regions-cut-by-slashes/description/