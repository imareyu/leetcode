class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        //sort(arr.begin(), arr.end());
        unordered_set<int> result;
        unordered_set<int> before;

        for(int i = 0;i < n;i++)
        {
            unordered_set<int> now;
            for(int be:before)
            {
                int in = be|arr[i];
                now.insert(in);
                result.insert(in);
            }
            now.insert(arr[i]);
            result.insert(arr[i]);
            before = now;
            int j = i+1;
            for(;j < n;j++)
            {
                if(arr[i] != arr[j])
                {
                    break;
                }
            }
            i = j-1;
        }
        return result.size();
    }
};
//https://leetcode.cn/problems/bitwise-ors-of-subarrays/description/