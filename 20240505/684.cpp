class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<set<int>> nodeSet;
        for(int i = 0;i < edges.size();i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            vector<int> addj;
            for(int j = 0;j < nodeSet.size();j++)
            {
                if(nodeSet[j].count(node1) > 0&&nodeSet[j].count(node2) > 0)
                    return edges[i];
                else
                {
                    if(nodeSet[j].count(node1))
                    {
                        addj.push_back(j);
                    }
                    if(nodeSet[j].count(node2))
                    {
                        addj.push_back(j);
                    }
                }
            }
            if(addj.size() == 0)
            {
                set<int> tempset;
                tempset.insert(node1);
                tempset.insert(node2);
                nodeSet.emplace_back(tempset);
            }
            if(addj.size() == 1)
            {
                int j1 = addj[0];
                nodeSet[j1].insert(node1);
                nodeSet[j1].insert(node2);
            }
            if(addj.size() == 2)
            {
                int j1 = addj[0];
                int j2 = addj[1];
                nodeSet[j1].insert(node1);
                nodeSet[j1].insert(node2);
                nodeSet[j1].insert(nodeSet[j2].begin(),nodeSet[j2].end());
                nodeSet.erase(nodeSet.begin() + j2);
            }
        }
        return {};
    }
};
//https://leetcode.cn/problems/redundant-connection/