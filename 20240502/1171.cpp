/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode*> data;
        ListNode* it = head;

        while(it)
        {
            if(it->val != 0)
                data.push_back(it);
            it = it->next;
        }

        while(data.size() > 0)
        {
            vector<int> sums(data.size(), 0);
            sums[0] = (data[0])->val;
            bool change = false;
            for(int i = 1;i < data.size();i++)
            {
                sums[i] = sums[i-1] + (data[i])->val;
                if(sums[i] == 0)
                {
                    for(int j = 0;j <= i;j++)
                        data.erase(data.begin());
                    change = true;
                    break;
                }
            }
            if(change)
                continue;
            for(int i = 0;i < sums.size();i++)
            {
                for(int j = i+1;j < sums.size();j++)
                {
                    if(sums[j] == sums[i])
                    {
                        for(int k = i;k < j;k++)
                        {
                            data.erase(data.begin()+i+1);
                        }
                        change = true;
                        break;
                    }
                }
                if(change)
                    break;
            }
            if(!change)
                break;
        }
        if(data.empty())
            return nullptr;
        for(int i = 0;i < data.size()-1;i++)
        {
            data[i]->next = data[i+1];
        }
        data[data.size()-1]->next = nullptr;
        return data[0];
    }
};
//https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/