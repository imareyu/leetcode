class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int mx = 0;

        for(int house:houses)
        {
            int index = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            if(index == heaters.size())
            {
                index--;
                int len = house - heaters[index];
                mx = max(mx, len);
            }
            else
            {
                if(heaters[index] == house)
                {
                    continue;
                }
                else
                {
                    int len1 = heaters[index] - house;
                    index--;
                    if(index >= 0)
                    {
                        int len2 = house - heaters[index];
                        mx = max(mx, min(len1, len2));
                    }
                    else
                    {
                        mx = max(mx, len1);
                    }
                }
            }
        }
        return mx;
    }
};
//https://leetcode.cn/problems/heaters/description/