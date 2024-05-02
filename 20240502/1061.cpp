class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<set<char>> data;

        for(int i = 0;i < n;i++)
        {
            char ch1 = s1[i];
            char ch2 = s2[i];
            vector<int> addi;

            for(int j = 0;j < data.size();j++)
            {
                if(data[j].count(ch1) > 0 || data[j].count(ch2) > 0)
                {//两个字符在集合里
                    addi.push_back(j);;
                }
            }
            if(addi.size() == 0)//没有出现过，成立一个新的集合
            {
                data.push_back(set<char>{ch1,ch2});
            }
            else
            {
                if(addi.size() == 1)
                {
                    data[addi[0]].insert(ch1);
                    data[addi[0]].insert(ch2);
                }
                else
                {
                    int i1 = addi[0];
                    int i2 = addi[1];
                    data[i1].insert(data[i2].begin(), data[i2].end());
                    data[i1].insert(ch1);
                    data[i1].insert(ch2);
                    data.erase(data.begin() + i2);
                }
            }
        }
        string ret = "";
        for(int i = 0;i < baseStr.size();i++)
        {
            char ch = baseStr[i];
            int j = 0;
            for(;j < data.size();j++)
            {
                if(data[j].count(ch) > 0)
                {
                    ret += *(data[j].begin());
                    break;
                }
            }
            if(j == data.size())
            {
                ret += ch;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/lexicographically-smallest-equivalent-string/