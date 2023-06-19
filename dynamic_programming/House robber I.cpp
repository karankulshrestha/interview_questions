/*
    uname: karankulx
    qname: House Robber I
    qlink: https://leetcode.com/problems/house-robber/description/
    companies: Google, Oyo, Microsoft, Airbnb, Uber
*/


// Top down or Recursion + Memoization Approach

class Solution {
public:
    int t[101];
    int solve(int i, int n, vector<int>& nums) {
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];
        int steal = nums[i] + solve(i + 2, n, nums);
        int skip = solve(i + 1, n, nums);
        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, nums);    
    }
};

// Bottom up Approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n + 1, 0);
        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i<=n; i++) {
            int steal = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];
            t[i] = max(steal, skip); 
        }
        return t[n];
    }
};