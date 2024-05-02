class Solution {
private:
    void add1(int i,vector<int>& data)
    {
        if(i >= data.size())
        {
            data.push_back(1);
            return ;
        }
        if(data[i]+1 < 10)
        {
            data[i]++;
        }
        else
        {
            data[i] = 0;
            add1(i+1, data);
        }
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> data;
        int sum = 0;
        long long num = n;

        while(num)
        {
            int yu = num%10;
            data.emplace_back(yu);
            sum += yu;
            num /= 10;
        }
        if(sum <= target)
        {
            return 0;
        }
        long long addNum = 0;
        long long mi = 1;
        for(int i = 0;i < data.size();i++)
        {
            //cout<<i<<" "<<data[i]<<endl;
            if(data[i] == 0)
            {
                mi *= 10;
                continue;
            }
            long long na = 10 - data[i];
            addNum += na * mi;
            data[i] = 0;
            add1(i+1,data);
            mi *= 10;
            sum = 0;
            for(int d:data)
            {
                sum+=d;
            }
            if(sum <= target)
            {
                break;
            }
        }
        return addNum;
    }
};
//https://leetcode.cn/problems/minimum-addition-to-make-integer-beautiful/description/