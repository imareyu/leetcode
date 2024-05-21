class Solution {
public:
    string frequencySort(string s) {
        map<char, int> chCount;

        for(char ch:s)
        {
            chCount[ch]++;
        }
        vector<pair<int,char>> data;

        for(auto [ch, count]:chCount)
        {
            data.emplace_back(count, ch);
        }
        sort(data.begin(), data.end(),[](const pair<int,char>& a,const pair<int,char>& b){
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first > b.first;
        });

        string ret = "";
        for(auto [count,ch]:data)
        {
            string str(count,ch);
            ret += str;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/sort-characters-by-frequency/