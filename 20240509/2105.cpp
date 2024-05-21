class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int left = 0;
        int leftCapa = capacityA;
        int right = n-1;
        int rightCapa = capacityB;
        int ret = 0;
        while(left <= right)
        {
            if(left == right)
            {
                int mx = max(leftCapa, rightCapa);
                if(mx < plants[left])
                {
                    ret++;
                }
                break;
            }
            else
            {
                if(leftCapa < plants[left])
                {
                    leftCapa = capacityA;
                    ret++;
                }
                leftCapa -= plants[left];
                left++;
                if(rightCapa < plants[right])
                {
                    rightCapa = capacityB;
                    ret++;
                }
                rightCapa -= plants[right];
                right--;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/watering-plants-ii/