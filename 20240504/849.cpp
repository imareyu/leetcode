class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> usedSeat;

        for(int i = 0;i < n;i++)
        {
            if(seats[i] == 1)
            {
                usedSeat.emplace_back(i);
            }
        }
        int ret = max(usedSeat[0]-0, n-1-usedSeat.back());
        for(int i = 0;i < usedSeat.size()-1;i++)
        {
            ret = max(ret, (usedSeat[i+1]-usedSeat[i])/2);
        }

        return ret;
    }
};
//https://leetcode.cn/problems/maximize-distance-to-closest-person/