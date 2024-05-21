class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        set<int> used;
        for(int i = 0;i < n;i++)
        {
            if(used.count(i) > 0)
                continue;
            deque<int> dq;
            dq.push_back(i);
            bool positive = (nums[i]>0);
            //cout<<"i = "<<i<<endl;
            while(true)
            {
                int index = dq.back();
                //cout<<index<<endl;
                int nextIndex = (nums[index] + index + n*1000)%n;
                if(nextIndex == index)
                {
                    break;
                }
                if(find(dq.begin(), dq.end(), nextIndex) == dq.end())
                {//没有出现
                    if((nums[nextIndex]>0) == positive )
                    {
                        dq.push_back(nextIndex);
                    }
                    else//不满足同正或同负
                    {
                        break;
                    }
                }
                else
                {//出现过
                    if(dq.size() > 1)
                        return true;
                    else
                        break;
                }
            }
            while(!dq.empty())
            {
                used.insert(dq.front());
                dq.pop_front();
            }
        }
        return false;
    }
};
//https://leetcode.cn/problems/circular-array-loop/