/*
    name: karankulx
    qname: Count Ways To Build Good Strings
    qlink: https://leetcode.com/problems/count-ways-to-build-good-strings/description/
    companies: Uber, Meta, Microsoft
    rating: Easy-Medium

*/

// Bottom-up approach

class Solution {
public:
    const int M = 1e9 + 7;
    int solve(int low, int high, int zero, int one, vector<int>& t) {
        for(int i = 1; i<=high; i++) {
            if(i - zero >= 0 ) {
                t[i] = (t[i]%M + t[i - zero]%M)%M;
            }; 
            if(i - one >= 0) {
                t[i] = (t[i]%M + t[i - one]%M)%M;
            };
        };
        int cnt = 0;
        for(int i = low; i<=high; i++) {
            cnt = (cnt%M + t[i]%M)%M;
        };
        return cnt;
    };

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> t(high + 1, 0);
        t[0] = 1;
        return solve(low, high, zero, one, t);
    }
};