class Solution {
private:
    int findfather(vector<int>& f,int i)
    {
        if(f[i] == i)
            return i;
        f[i] = findfather(f, f[i]);
        return f[i];
    }
    void uniondata(vector<int>& f, int x, int y)
    {
        int xf = findfather(f, x);
        int yf = findfather(f, y);
        f[xf] = yf;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        for (const auto& e: allowedSwaps) {
            uniondata(f, e[0], e[1]);
        }
        unordered_map<int, unordered_set<int>> bc;
        for(int i = 0;i < n;i++)
        {
            int fi = findfather(f, i);
            bc[fi].insert(i);
        }
        int ret = n;
        for(auto [fa, sons] : bc)
        {
            if(sons.size() == 1)
            {
                int index = *sons.begin();
                if(source[index] == target[index])
                {
                    ret--;
                }
            }
            else
            {
                map<int,int> data;
                for(auto index : sons)
                {
                    data[target[index]]++;
                }
                for(auto index : sons)
                {
                    if(data.count(source[index]) > 0)
                    {
                        data[source[index]]--;
                        if(data[source[index]] == 0)
                        {
                            data.erase(source[index]);
                        }
                        ret--;
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations/