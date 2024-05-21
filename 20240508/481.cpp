class Solution {
public:
    int magicalString(int n) {
        if(n < 4)
            return 1;
        string str = "122";
        int lastnum = 2;
        int index = 2;
        int ret = 1;

        while(str.size() < n)
        {
            if(str[index] == '1')
            {
                lastnum = 3 - lastnum;
                str += to_string(lastnum);
                if(lastnum == 1)
                    ret++;
            }
            else
            {
                lastnum = 3 - lastnum;
                str += to_string((lastnum)*11);
                if(lastnum == 1)
                {
                    if(str.size() <= n)
                        ret+=2;
                    else
                    {
                        ret++;
                    }
                }
            }
            index++;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/magical-string/