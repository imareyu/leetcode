class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> js;

        for(int i = 0;i < emails.size();i++)
        {
            string localName = "";
            string comName = "";
            int j = 0;
            for(;j < emails[i].size();j++)
            {
                if(emails[i][j] == '@')
                {
                    j++;
                    break;
                }
                localName += emails[i][j];
            }
            comName = emails[i].substr(j);
            //处理本地名
            string localNameDeal = "";
            for(j = 0;j < localName.size();j++)
            {
                if(localName[j] == '+')
                {
                    break;
                }
                if(localName[j] != '.')
                {
                    localNameDeal += localName[j];
                }
            }
            js.insert(localNameDeal + "@" + comName);
        }
        return js.size();
    }
};
//https://leetcode.cn/problems/unique-email-addresses/description/