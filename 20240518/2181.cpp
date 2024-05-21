class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* left = head;
        ListNode* ret = new ListNode();
        ListNode* it = ret;

        while(left && left->next)
        {
            ListNode* right = left->next;
            int sum = 0;
            while(right && right->val != 0)
            {
                sum += right->val;
                right = right->next;
            }
            it->next = new ListNode(sum);
            it = it->next;
            left = right;
        }
        return ret->next;
    }
};
//https://leetcode.cn/problems/merge-nodes-in-between-zeros/