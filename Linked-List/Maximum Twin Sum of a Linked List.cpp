/*
    uname: karankulx
    qname: Maximum Twin Sum of a Linked List
    rating: easy
    companies: Facebook, Amazon, Netflix, Google
    qlink: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
 */

// Approach 1

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head != nullptr) {
            int n = head->val;
            v.push_back(n);
            head = head->next;
        };
        int s = v.size();
        vector<int> sums;
        for(int i = 0; i<s; i++) {
            int temp = v[i] + v[s-i-1];
            sums.push_back(temp);
        };
        sort(sums.begin(), sums.end());
        return sums[s-1];
    }
};

// Approach 2

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        int s = 0;
        while(temp != nullptr){
            s++;
            temp = temp->next;
        };
        int i = 0;
        ListNode* temp1 = head;
        while(i != s/2) {
          i++;
          st.push(temp1->val);
          temp1 = temp1->next;  
        };
        int sum = 0;
        while(temp1 != nullptr) {
            int tempSum = st.top() + temp1->val;
            sum = max(sum, tempSum);
            st.pop();
            temp1 = temp1->next;
        };
        return sum;      
    };
};

