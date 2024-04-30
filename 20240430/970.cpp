class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound < 2)
            return {};
        vector<int> xnums;
        vector<int> ynums;
        set<int> result;
        if(x == 1)
        {
            xnums.push_back(1);
        }
        else
        {
            int num = 1;
            while(num < bound)
            {
                xnums.push_back(num);
                num = num * x;
            }
        }
        if(y == 1)
        {
            ynums.push_back(1);
        }
        else
        {
            int num = 1;
            while(num < bound)
            {
                ynums.push_back(num);
                num = num * y;
            }
        }

        for(int i = 0;i < xnums.size();i++)
        {
            for(int j = 0;j < ynums.size();j++)
            {
                int sum = xnums[i] + ynums[j];
                if(sum <= bound)
                {
                    result.insert(sum);
                }
                else
                {
                    break;
                }
            }
        }
        vector<int> ret(result.begin(), result.end());
        return ret;
    }
};
//https://leetcode.cn/problems/powerful-integers/description/