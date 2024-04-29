class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ret(n);
        vector<vector<int>> ha(s.size(), vector<int>(26, 0));

        ha[0][s[0]-'a']++;
        for(int i = 1;i < s.size();i++)
        {
            ha[i] = ha[i-1];
            ha[i][s[i]-'a']++;
        }
        cout<<"aaa"<<endl;
        for(int i = 0;i < n;i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int count = queries[i][2];
            bool hw = true;
            //260k
            int sum = 0;
            if(left-1 >= 0)
            {
                for(int j = 0;j < 26;j++)
                {
                    sum += (ha[right][j]- ha[left-1][j]) % 2;//abcde
                }
            }
            else
            {
                for(int j = 0;j < 26;j++)
                {
                    sum += ha[right][j] % 2;//abcde
                }
            }
            //cout<<sum<<"  "<<count<<endl;
            if(sum / 2 > count)
                hw = false;
            ret[i] = hw;
        }

        return ret;
    }
};
//https://leetcode.cn/problems/can-make-palindrome-from-substring/description/