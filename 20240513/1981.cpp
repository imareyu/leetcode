class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        //vector<int> addsums(4901, 0);
        unordered_set<int> used;

        for(int i = 0;i < m;i++)
        {
            unordered_set<int> tempused;
            for(int j = 0;j < n;j++)
            {
                if(i == 0)
                {
                    tempused.insert(mat[i][j]);
                }
                for(auto index:used)
                {
                    tempused.insert(mat[i][j] + index);
                }
            }
            vector<int> data(tempused.begin(), tempused.end());
            sort(data.begin(), data.end());
            while(data.size() >= 2 && data[data.size()-2] > target)
            {
                data.pop_back();
            }
            used.clear();
            used.insert(data.begin(), data.end());
            //cout<<used.size()<<endl;
        }
        int ret = INT_MAX;
        for(auto index:used)
        {
            //cout<<index<<endl;
            if(index > target)
            {
                ret = min(ret, index-target);
            }
            else
            {
                ret = min(ret, target - index);
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimize-the-difference-between-target-and-chosen-elements/