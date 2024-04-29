class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int> peopleMap;//体重  的 个数
        for(int i = 0;i < people.size();i++)
        {
            peopleMap[people[i]]++;
        }
        vector<pair<int, int>> data;
        for(auto [wei,count]: peopleMap)
        {
            data.emplace_back(wei,count);
        }

        int left = 0;
        int ret = 0;
        int i = 0;
        for(i = data.size()-1;i > left;)
        {
            if(data[i].second == 0)
            {
                i--;
                continue;
            }
            if(data[left].second == 0)
            {
                left++;
                continue;
            }
            int weight = data[i].first;
            int count = data[i].second;
            if(weight + data[left].first <= limit)
            {
                int subcount = min(count, data[left].second);
                data[i].second -= subcount;
                data[left].second -= subcount;
                ret += subcount;
                if(data[i].second == 0)
                {
                    i--;
                }
                if(data[left].second == 0)
                {
                    left++;
                }
            }
            else
            {
                ret += count;
                data[i].second = 0;
                i--;
            }
        }
        //cout<<ret;
        if(data[i].second > 0)
        {
            if(data[i].first * 2 <= limit)
            {
                ret += (data[i].second+1)/2;
            }
            else
            {
                ret += data[i].second;
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/boats-to-save-people/description/