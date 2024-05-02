class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        set<int> equals;
        int ret = 0;

        for(int i = 0;i < dominoes.size();i++)
        {
            if(equals.count(i) > 0)
            {
                continue;
            }
            int count = 0;
            for(int j = i+1;j < dominoes.size();j++)
            {
                if((dominoes[i][0] == dominoes[j][0]&&dominoes[i][1] == dominoes[j][1]) ||
                    (dominoes[i][0] == dominoes[j][1]&&dominoes[i][1] == dominoes[j][0]) )
                {
                    count++;
                    equals.insert(j);
                }
            }
            if(count > 0)
                ret += count*(count+1)/2;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/number-of-equivalent-domino-pairs/