class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int woner = arr[0];
        int wincount = 0;
        for(int i = 1;i < n && wincount < k;i++)
        {
            if(arr[i] > woner)
            {
                woner = arr[i];
                wincount = 1;
            }
            else
            {
                wincount++;
            }
        }
        return woner;
    }
};
//https://leetcode.cn/problems/find-the-winner-of-an-array-game/description/