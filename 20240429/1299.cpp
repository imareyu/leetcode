class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ret(n, -1);
        int maxNum = arr.back();

        for(int i = n-2;i >= 0;i--)
        {
            ret[i] = maxNum;
            if(arr[i] > maxNum)
            {
                maxNum = arr[i];
            }
        }

        return ret;
    }
};
//https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/description/