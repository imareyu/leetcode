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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = nullptr;
        ListNode* big = nullptr;
        ListNode* smallIt = nullptr;
        ListNode* bigIt = nullptr;
        ListNode* it = head;

        while(it)
        {
            if(it->val < x)
            {
                if(small == nullptr)
                {
                    small = smallIt = it;
                    it = it->next;
                    smallIt->next = nullptr;
                }
                else
                {
                    smallIt->next = it;
                    smallIt = it;
                    it = it->next;
                    smallIt->next = nullptr;
                }
            }
            else
            {
                if(big == nullptr)
                {
                    big = bigIt = it;
                    it = it->next;
                    bigIt->next = nullptr;
                }
                else
                {
                    bigIt->next = it;
                    bigIt = it;
                    it = it->next;
                    bigIt->next = nullptr;
                }
            }
        }
        if(small)
        {
            smallIt->next = big;
        }
        else
        {
            small = big;
        }
        return small;
    }
};
//https://leetcode.cn/problems/partition-list/description/