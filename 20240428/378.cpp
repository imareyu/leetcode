class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        for(int i = 0;i < matrix.size();i++)
        {
            pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }

        k--;
        while(k > 0)
        {
            auto it = pq.top();
            int num = it.first;
            int x = it.second.first;
            int y = it.second.second;
            //cout<<num<<" " <<x<<" "<<y<<endl;
            pq.pop();
            y++;
            if(y < n)
            {
                pq.push(make_pair(matrix[x][y], make_pair(x, y)));
            }
            k--;
        }
        auto it = pq.top();
        int num = it.first;
        return num;
    }
};
//https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/description/