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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
        {
            return nullptr;
        }
        deque<ListNode*> dq;
        ListNode* slow = head;
        ListNode* fast = head;

        dq.emplace_back(nullptr);
        dq.emplace_back(head);

        while(fast->next)
        {
            slow = slow->next;
            dq.pop_front();
            dq.emplace_back(slow);
            fast = fast->next;
            if(fast->next)
            {
                fast = fast->next;
            }
        }
        ListNode* before = dq.front();
        before->next = slow->next;
        return head;
    }
};
//https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/