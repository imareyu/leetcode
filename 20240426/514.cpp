class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringlen = ring.size();
        int n = ringlen;

        vector<vector<int>> ringhash(26);
        for(int i = 0;i < ringlen;i++)
        {
            ringhash[ring[i]-'a'].push_back(i);
        }
        vector<vector<int>> dp(ringlen, vector<int>(key.size(),100000));

        int ret = INT_MAX;        
        char c = key[0];
        for(int i = 0;i < ringhash[c-'a'].size();i++)
        {
            int j = ringhash[c-'a'][i];
            dp[j][0] = min(j, n-j);
            //ret = min(ret, dp[j][0]);
        }

        for(int j = 1;j < key.size();j++)
        {
            c = key[j];
            cout<<c<<endl;
            for(int i = 0;i < ringhash[c-'a'].size();i++)
            {
                int k = ringhash[c-'a'][i];
                cout<<"k="<<k<<endl;
                for(int z = 0;z < ringlen;z++)
                {
                    dp[k][j] = min(dp[k][j], dp[z][j-1]+min(abs(k-z), n-abs(k-z)));//z=3 k =0 n=5
                    //if(j == key.size()-1&&dp[k][j] < ret)
                    //{
                    //    ret = dp[k][j];
                    //}
                }
            }
        }
        
            for(int j = 0;j < dp.size();j++)
            {
                ret = min(ret, dp[j][key.size()-1]);
            }

        return ret+key.size();
    }
};
//https://leetcode.cn/problems/freedom-trail/?envType=daily-question