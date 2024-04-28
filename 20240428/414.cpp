class Solution {
private:
    int colu = 3;
    void update(vector<int>& data,int num)
    {
        if(find(data.begin(),data.end(),num) != data.end())
        {
            return ;
        }
        data.push_back(num);
        sort(data.begin(), data.end(), [](const int a,const int b)
        {
            return a > b;
        }
        );
        if(data.size() > colu)
        {
            while(data.size() > colu)
            {
                data.pop_back();
            }
        }
    }
public:
    int thirdMax(vector<int>& nums) {
        vector<int> data;
        for(int i = 0;i < nums.size();i++)
        {
            update(data, nums[i]);
        }
        if(data.size() == 3)
            return data[2];
        return data[0];
    }
};
//https://leetcode.cn/problems/third-maximum-number/description/