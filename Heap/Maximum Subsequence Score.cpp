/*
    uname: karankulx
    qname: Maximum Subsequence Score
    qlink: https://leetcode.com/problems/maximum-subsequence-score/description/
    rating: medium - Hard
    companies: Google, Amazon
*/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vec;
        for(int i = 0; i<nums1.size(); i++) {
            vec.push_back({nums2[i], nums1[i]});
        };
        sort(vec.rbegin(), vec.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long curr_sum = 0;
        for(int i = 0; i<k-1; i++) {
            pq.push(vec[i].second);
            curr_sum += vec[i].second;
        };
        for(int i = k -1; i<nums1.size(); i++) {
            curr_sum += vec[i].second;
            pq.push(vec[i].second);
            ans = max(ans, curr_sum * vec[i].first);
            curr_sum -= pq.top();
            pq.pop();
        };
        return ans;
    }
};