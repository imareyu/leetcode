class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsf(words.size(), 0);

        for(int i = 0;i < words.size();i++)
        {
            vector<int> ha(26, 0);
            for(int j = 0;j < words[i].size();j++)
            {
                ha[words[i][j]-'a']++;
            }
            int f = 0;
            for(int j = 0;j < 26;j++)
            {
                if(ha[j])
                {
                    f = ha[j];
                    break;
                }
            }
            wordsf[i] = f;
        }
        sort(wordsf.begin(), wordsf.end());
        vector<int> ret(queries.size(), 0);

        for(int i = 0;i < queries.size();i++)
        {
            vector<int> ha(26, 0);
            for(int j = 0;j < queries[i].size();j++)
            {
                ha[queries[i][j]-'a']++;
            }
            int f = 0;
            for(int j = 0;j < 26;j++)
            {
                if(ha[j])
                {
                    f = ha[j];
                    break;
                }
            }
            int result = wordsf.end() - upper_bound(wordsf.begin(), wordsf.end(), f);
            ret[i] = result;
        }

        return ret;
    }
};
//https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/description/