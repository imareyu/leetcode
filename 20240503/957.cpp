class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        string str = "";
        map<string, int> usedMap;
        vector<string> usedVec;

        for(int i = 0;i < cells.size();i++)
        {
            str += char('0'+cells[i]);
        }
        usedMap[str] = 0;
        usedVec.push_back(str);
        
        int startStrIndex=-1;
        int i = 0;
        for(;i < n;i++)
        {
            str = usedVec.back();
            string newStr = "0";
            for(int j = 1;j < 7;j++)
            {
                if(str[j-1] == str[j+1])
                {
                    newStr += '1';
                }
                else
                {
                    newStr += '0';
                }
            }
            newStr += '0';
            //cout<<newStr<<endl;
            if(usedMap.find(newStr) != usedMap.end())
            {
                startStrIndex = usedMap[newStr];
                break;
            }
            else
            {
                usedMap[newStr] = usedVec.size();
                usedVec.emplace_back(newStr);
            }
        }
        if(i == n)
        {
            vector<int> ret;
            for(char ch:usedVec.back())
                ret.push_back(ch-'0');
            return ret;
        }
        n = (n-startStrIndex)%(usedVec.size() - startStrIndex) + startStrIndex;
        vector<int> ret;
        for(char ch:usedVec[n])
            ret.push_back(ch-'0');
        return ret;
    }
};
/*0 1 2  3 4 5  6  7  in = 3
         8 9 10 11 12
         11 12 13 14
(n-in)%(size-in) + in
(n-3)%(8-3)+3
*/
//https://leetcode.cn/problems/prison-cells-after-n-days/