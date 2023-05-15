/*
    uname: karankulx
    difficulty: easy-medium
    companies: Microsoft, Amazon
    link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
    name:  Swapping Nodes in a Linked List
*/

class Solution {
public:
    int findLen(ListNode* head) {
        int k = 0;
        while(head != nullptr) {
            head = head->next;
            k += 1;
        };
        return k;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int l = findLen(head);
        int ks = k;
        ListNode* node1 = head;
        for(int i = 1; i<ks; i++) {
            node1 = node1->next;
        };

        int ke = l - k + 1;
        ListNode* node2 = head;
        for(int i = 1; i<ke; i++) {
            node2 = node2->next;
        };

        swap(node1->val, node2->val);

        return head;  
    }
};