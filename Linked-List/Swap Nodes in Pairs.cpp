/*
    uname: karankulx
    companies: Meta
    name: Swap Nodes in Pairs
    qlink: https://leetcode.com/problems/swap-nodes-in-pairs/description/
    rating: easy-medium
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* node1;
        ListNode* node2;
        while(temp != nullptr && temp->next != nullptr) {
            node1 = temp;
            node2 = temp->next;
            swap(node1->val, node2->val);
            temp = temp->next->next;
        };
        return head;
    }
};