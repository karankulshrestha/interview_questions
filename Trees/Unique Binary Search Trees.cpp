/*
    uname: karankulx
    qname: Unique Binary Search Trees
    qlink: https://leetcode.com/problems/unique-binary-search-trees/description/
    companies: Tower Research
*/

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int vars = 0;
        for(int i = 1; i<=n; i++) {
            vars += solve(i - 1, dp)*solve(n - i, dp);
        }
        return dp[n] = vars;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};