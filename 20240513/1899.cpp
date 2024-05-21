class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int fir = -1;
        int sec = -1;
        int thi = -1;
        int n = triplets.size();

        for(int i = 0;i < n;i++)
        {
            int num0 = triplets[i][0];
            int num1 = triplets[i][1];
            int num2 = triplets[i][2];
            if(num0 <= target[0] && num1 <= target[1] && num2 <= target[2])
            {
                fir = max(fir, num0);
                sec = max(sec, num1);
                thi = max(thi, num2);
            }
        }
        if(fir == target[0] && sec == target[1] && thi == target[2])
        {
            return true;
        }
        return false;
    }
};
//https://leetcode.cn/problems/merge-triplets-to-form-target-triplet/description/