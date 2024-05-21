class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        long long tempNum = num;
        int negative = false;
        if(tempNum < 0)
        {
            negative = true;
            tempNum = -tempNum;
        }
        vector<int> data;
        while(tempNum > 0)
        {
            int yu = tempNum % 10;
            data.emplace_back(yu);
            tempNum /= 10;
        }
        sort(data.begin(), data.end());

        long long ret = 0;
        if(negative)
        {//负数，那就搞绝对值最大的
            for(int j = data.size()-1;j >= 0;j--)
            {
                ret = ret*10 + data[j];
            }
            ret = -ret;
        }
        else
        {
            //不是负数，那就把前缀0往后搞一搞
            if(data[0] == 0)
            {
                for(int i = 0;i < data.size();i++)
                {
                    if(data[i] != 0)
                    {
                        swap(data[0], data[i]);
                        break;
                    }
                }
            }
            for(int i = 0;i < data.size();i++)
            {
                ret = ret*10 + data[i];
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/smallest-value-of-the-rearranged-number/