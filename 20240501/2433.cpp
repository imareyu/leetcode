class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret;
        ret.push_back(pref[0]);
        int huo = pref[0];

        for(int i = 1;i < pref.size();i++)
        {
            int result = huo ^ pref[i];
            ret.push_back(result);
            huo = huo ^ result;
        }
        return ret;
    }
};
//异或，相同得0，不同得1
//https://leetcode.cn/problems/find-the-original-array-of-prefix-xor/description/