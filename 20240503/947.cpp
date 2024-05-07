class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<pair<int,int>> points;

        for(int i = 0;i < stones.size();i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            points.push_back(make_pair(x, y));
        }
        int ret = 0;
        while(points.size() > 0)
        {
            auto [x,y] = *(points.begin());
            vector<pair<int,int>> addPo;
            addPo.emplace_back(x, y);
            points.erase(points.begin());
            for(int i = 0;i < addPo.size();i++)
            {
                auto [x1,y1] = addPo[i];
                for(int j = 0;j < points.size();j++)
                {
                    auto [x2,y2] = *(points.begin()+j);
                    if(x1 == x2 || y1 == y2)
                    {
                        addPo.emplace_back(x2,y2);
                        points.erase(points.begin()+j);
                        j--;
                    }
                }
            }
            ret++;
        }
        return stones.size()-ret;
    }
};
//https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/description/