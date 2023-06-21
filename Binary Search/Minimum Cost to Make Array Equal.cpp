/*
    uname: karankulx
    qname: Minimum Cost to Make Array Equal
    qlink: https://leetcode.com/problems/minimum-cost-to-make-array-equal/
    companies: Google
*/

// Approach 1: Using Binary Search
class Solution {
public:
    typedef long long ll;
    ll findCost(vector<int>& nums, vector<int>& cost, ll val) {
        ll cst = 0;
        for(int i = 0; i<nums.size(); i++) {
            cst += (ll) abs(val - nums[i])*cost[i];
        };
        return cst;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans = INT_MAX;
        ll left = *min_element(nums.begin(), nums.end());
        ll right = *max_element(nums.begin(), nums.end());
        while(left <= right) {
            ll mid = left + (right - left)/2;
            ll c1 = findCost(nums, cost, mid);
            ll c2 = findCost(nums, cost, mid + 1);

            ans = min(c1, c2);

            if(c1 < c2) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};