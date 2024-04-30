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
    vector<int> nextLargerNodes(ListNode* head) {
        int i = 0;
        ListNode* it = head;
        stack<pair<int,int>> sta;
        vector<int> ret;

        while(it)
        {
            while(!sta.empty())
            {
                auto [v,index] = sta.top();
                if(it->val > v)
                {
                    ret[index] = it->val;
                    sta.pop();
                }
                else
                {
                    break;
                }
            }
            sta.push(make_pair(it->val, i));

            it = it->next;
            i++;
            ret.push_back(0);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/next-greater-node-in-linked-list/