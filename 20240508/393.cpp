class Solution {
private:
    pair<int,int> get(int num)
    {
        pair<int,int> ret;
        ret.first = (num>>7)&1;
        ret.second = 0;
        if(((num>>7)&1) == 1)
        {
            ret.second++;
            if(((num>>6)&1) == 1)
            {
                ret.second++;
                if(((num>>5)&1) == 1)
                {
                    ret.second++;
                    if(((num>>4)&1) == 1)
                    {
                        ret.second++;
                        if(((num>>3)&1) == 1)
                        {
                            ret.second++;
                        }
                    }
                }
            }
        }
        return ret;
    }
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();

        for(int i = 0;i < n;)
        {
            pair<int,int> res = get(data[i]);
            if(res.first == 0)
            {
                i++;
            }
            else//最高为1
            {
                int len = res.second;
                if(len == 1 || len>4)
                {
                    return false;
                }
                int j = 1;
                for(;j < len && j+i < n;j++)
                {
                    pair<int,int> res2 = get(data[j+i]);
                    if(res2.first == 1 && res2.second == 1)
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if(j < len)
                {
                    return false;
                }
                i += len;
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/utf-8-validation/