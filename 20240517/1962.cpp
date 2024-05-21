class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int,vector<int>, less<int>> pq(piles.begin(), piles.end());
        int sum = accumulate(piles.begin(), piles.end() ,0);
        int subNum = 0;

        for(int i = 0;i < k;i++)
        {
            int mx = pq.top();
            pq.pop();
            subNum += mx/2;
            mx = (mx+1) / 2;
            pq.push(mx);            
        }
        return sum - subNum;
    }
};
//https://leetcode.cn/problems/remove-stones-to-minimize-the-total/description/