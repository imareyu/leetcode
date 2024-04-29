class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ret;
        set<int> deletefolder;//已经删除的
        int n = folder.size();
        sort(folder.begin(), folder.end());

        for(int i = 0;i < n;i++)
        {
            if(deletefolder.count(i) > 0)
            {
                continue;
            }
            ret.emplace_back(folder[i]);
            cout<<i <<"===="<<folder[i]<<endl;
            for(int j = i+1;j < n;j++)
            {
                cout<<j<<"    "<< folder[j]<<endl;
                if(deletefolder.count(j) > 0)
                {
                    continue;
                }
                int k = 0;
                for(;k < folder[i].size();k++)
                {
                    if(folder[i][k] != folder[j][k])
                    {
                        break;
                    }
                }
                if(k == folder[i].size())
                {
                    if(folder[j][k] == '/')
                    {
                        deletefolder.insert(j);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/description/