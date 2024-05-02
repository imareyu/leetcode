class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int num = n;
        vector<int> data;
        int mi = 1;

        while(num)
        {
            int yu = num % 2;
            if(yu == 1)
            {
                data.push_back(yu*mi);
                //cout<<yu*mi<<endl;
            }
            mi *= 2;
            num /= 2;
        }
        vector<int> ret;
        for(int i = 0;i < queries.size();i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            long long res = data[left];
            for(int j = left+1;j <= right;j++)
            {
                res = res * data[j]%1000000007;
            }
            ret.emplace_back(res);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/range-product-queries-of-powers/