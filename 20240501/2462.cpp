class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0;
        int right = n-1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqleft;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqright;
        set<int> used;

        while(left < candidates)
        {
            pqleft.push(make_pair(costs[left], left));
            left++;
        }
        while(right > n-candidates-1)
        {
            pqright.push(make_pair(costs[right], right));
            right--;
        }
        long long ret = 0;
        for(int i = 0;i < k;i++)
        {
            auto [valleft, ileft] = pqleft.top();
            auto [valright, iright] = pqright.top();
            if(valleft < valright)
            {
                ret += valleft;
                pqleft.pop();
                used.insert(ileft);
                while(left < n)
                {
                    if(used.count(left) == 0)//没用过
                    {
                        pqleft.push(make_pair(costs[left],left));
                        left++;
                        break;
                    }
                    left++;
                }
            }
            else
            {
                if(valleft > valright)
                {
                    ret += valright;
                    pqright.pop();
                    used.insert(iright);
                    while(right >= 0)
                    {
                        if(used.count(right) == 0)//没用过
                        {
                            pqright.push(make_pair(costs[right], right));
                            right--;
                            break;
                        }
                        right--;
                    }
                }
                else//相等
                {
                    if(ileft == iright)
                    {
                        ret += valleft;
                        pqleft.pop();
                        used.insert(ileft);
                        while(left < n)
                        {
                            if(used.count(left) == 0)//没用过
                            {
                                pqleft.push(make_pair(costs[left],left));
                                left++;
                                break;
                            }
                            left++;
                        }
                        pqright.pop();
                        while(right >= 0)
                        {
                            if(used.count(right) == 0)//没用过
                            {
                                pqright.push(make_pair(costs[right], right));
                                right--;
                                break;
                            }
                            right--;
                        }
                    }
                    else
                    {
                        ret += valleft;
                        pqleft.pop();
                        used.insert(ileft);
                        while(left < n)
                        {
                            if(used.count(left) == 0)//没用过
                            {
                                pqleft.push(make_pair(costs[left],left));
                                left++;
                                break;
                            }
                            left++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/total-cost-to-hire-k-workers/description/