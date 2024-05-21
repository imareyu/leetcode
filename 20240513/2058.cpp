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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next ||!head->next->next)
        {
            return {-1, -1};
        }

        ListNode* leftnode = head;
        ListNode* midnode = head->next;
        ListNode* rightnode = midnode->next;
        int i = 1;

        vector<int> data;

        while(rightnode)
        {
            if((midnode->val < leftnode->val && midnode->val < rightnode->val) ||
                (midnode->val > leftnode->val && midnode->val > rightnode->val))
            {
                data.emplace_back(i);
            }
            leftnode = midnode;
            midnode = rightnode;
            rightnode = rightnode->next;
            i++;
        }
        if(data.size() < 2)
        {
            return {-1, -1};
        }
        int mn = INT_MAX;
        int mx = data[data.size()-1] - data[0];
        vector<int> ret(2, 0);
        for(int i = 1;i < data.size();i++)
        {
            mn = min(mn, data[i] - data[i-1]);
        }
        ret[0] = mn;
        ret[1] = mx;
        return ret;
    }
};
//https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/