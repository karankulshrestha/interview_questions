/*
    name: Solving Questions With Brainpower
    companies: Google, Oracle, Amazon
    qlink: https://leetcode.com/problems/solving-questions-with-brainpower/description/
    rating: easy-medium
*/

class Solution {
public:
    int n;
    long long solve(int i, vector<vector<int>>& q, vector<long long>& t) {
        if(i>=n) return 0;
        if(t[i] != -1) {
            return t[i];
        };
        long long not_skip = q[i][0] + solve(i + q[i][1] + 1, q, t);
        long long skip = solve(i + 1, q, t);

        return t[i] = max(not_skip, skip);
    };

    long long mostPoints(vector<vector<int>>& q) {
        n = q.size();
        vector<long long> t(n, -1);
        return solve(0, q, t);
    }
};