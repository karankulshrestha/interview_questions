/*
    uname: karankulx
    qlink: https://leetcode.com/problems/house-robber-ii/description/
    qname: House Robber II
    companies: Microsoft
*/

class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> t(n + 1, 0);
        // case 1 when 1st element 
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            int steal = nums[i - 1] + ((i-2 > 0) ? t[i-2] : 0);
            int skip = t[i - 1];
            t[i] = max(steal, skip);
        };
        int r1 = t[n - 1];

        t.clear();

        //case 2 when 2nd element 
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            int steal = nums[i - 1] + ((i - 2 > 0) ? t[i - 2] : 0);
            int skip = t[i-1];
            t[i] = max(skip, steal);
        };
        int r2 = t[n];
        return max(r1, r2);

    };

    int rob(vector<int>& nums) {
        return solve(nums);
    }
};