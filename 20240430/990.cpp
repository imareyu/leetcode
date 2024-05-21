class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<set<char>> data;
        vector<int> notequalId;

        for(int i = 0;i < equations.size();i++)
        {
            char ch1 = equations[i][0];
            //int index1 = ch1 - 'a';
            char ch2 = equations[i][3];
            //int index2 = ch2 - 'a';
            if(ch1 == ch2)
            {
                if(equations[i][1] == '=')
                    continue;
                else
                    return false;
            }
            
            if(equations[i][1] == '!')
            {
                notequalId.push_back(i);
                continue;
            }
            vector<int> addj;
            for(int j = 0;j < data.size();j++)
            {
                if(data[j].count(ch1) || data[j].count(ch2))
                {
                    data[j].insert(ch1);
                    data[j].insert(ch2);
                    addj.push_back(j);
                }
            }
            if(addj.size() == 0)
            {
                set<char> temp;
                temp.insert(ch1);
                temp.insert(ch2);
                data.push_back(temp);
            }
            else
            {
                data[addj[0]].insert(ch1);
                data[addj[0]].insert(ch2);
                for(int j = addj.size()-1;j > 0;j--)
                {
                    data[addj[0]].insert(data[addj[j]].begin(), data[addj[j]].end());
                    data.erase(data.begin() + addj[j]);
                }
            }
        }
        for(int index:notequalId)//不相等的
        {
            char ch1 = equations[index][0];
            char ch2 = equations[index][3];

            for(int j = 0;j < data.size();j++)
            {
                if(data[j].count(ch1) && data[j].count(ch2))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/satisfiability-of-equality-equations/