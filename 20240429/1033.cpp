class Solution {
private:
    int backtrace(int a, int b, int c)
    {
        if(b-a == 1 && c-b == 1)
            return 0;
        if(b-a == 1 || c-b == 1)
            return 1;
        if(b-a == 2 || c-b == 2)
            return 1;
        return 2;
    }
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> data;
        data.push_back(a);
        data.push_back(b);
        data.push_back(c);
        sort(data.begin(), data.end());

        a = data[0];
        b = data[1];
        c = data[2];

        int maxret = b-a-1+c-b-1;
        int minret = backtrace(a,b,c);
        vector<int> ret;
        ret.push_back(minret);
        ret.push_back(maxret);
        return ret;
    }
};
//https://leetcode.cn/problems/moving-stones-until-consecutive/description/