class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> data;
        string str;
        vector<string> ret;
        text += ' ';

        for(int i = 0;i < text.size();i++)
        {
            if(text[i] == ' ')
            {
                if(str.empty())
                {
                    continue;
                }
                data.push_back(str);
                str = "";
                if(data.size() == 3)
                {
                    if(first == data[0] && second == data[1])
                    {
                        ret.emplace_back(data[2]);
                    }
                    data.erase(data.begin());
                }
            }
            else
            {
                str += text[i];
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/occurrences-after-bigram/