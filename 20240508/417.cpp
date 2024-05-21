class Solution {
private:
    vector<pair<int,int>> dirc = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        set<pair<int, int>> Po;//太平洋
        set<pair<int, int>> Ao;//大西洋
        vector<pair<int, int>> vecPo;
        vector<pair<int, int>> vecAo;
        for(int i = 0;i < n;i++)
        {
            vecPo.emplace_back(0, i);
            Po.insert(make_pair(0, i));
        }
        for(int i = 1;i < m;i++)
        {
            vecPo.emplace_back(i, 0);
            Po.insert(make_pair(i, 0));
        }
        int index = 0;
        while(index < vecPo.size())
        {
            auto [x,y] = vecPo[index];
            for(auto [xd,yd]: dirc)
            {
                if(x+xd >= 0 && x+xd < m && y+yd >= 0 && y+yd < n && heights[x+xd][y+yd] >= heights[x][y] && Po.count(make_pair(x+xd,y+yd)) == 0)
                {
                    vecPo.emplace_back(x+xd, y+yd);
                    Po.insert(make_pair(x+xd, y+yd));
                }
            }
            index++;
        }
        for(int i = 0;i < n;i++)
        {
            vecAo.emplace_back(m-1, i);
            Ao.insert(make_pair(m-1, i));
        }
        for(int i = 0;i < m-1;i++)
        {
            vecAo.emplace_back(i, n-1);
            Ao.insert(make_pair(i, n-1));
        }
        index = 0;
        while(index < vecAo.size())
        {
            auto [x,y] = vecAo[index];
            for(auto [xd,yd]: dirc)
            {
                if(x+xd >= 0 && x+xd < m && y+yd >= 0 && y+yd < n && heights[x+xd][y+yd] >= heights[x][y] && Ao.count(make_pair(x+xd,y+yd)) == 0)
                {
                    vecAo.emplace_back(x+xd, y+yd);
                    Ao.insert(make_pair(x+xd, y+yd));
                }
            }
            index++;
        }
        vector<vector<int>> ret;
        for(auto [x,y]:Po)
        {
            if(Ao.count(make_pair(x,y)) > 0)
                ret.emplace_back(vector<int>{x,y});
        }
        return ret;
    }
};
//https://leetcode.cn/problems/pacific-atlantic-water-flow/