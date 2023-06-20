/*
    uname: karankulx
    qlink: https://leetcode.com/problems/k-radius-subarray-averages/
    qname: K Radius Subarray Averages
    companies: Amazon, Microsoft
*/

// Naive Approach leads TLE

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size() - 1;
        vector<int> ans(n + 1, 0); 
        for(int i = 0; i<=n; i++) {
            int sum = 0;
            if(i < k || n - i < k) {
                ans[i] = -1;
            } else {
                int init = i - k;
                int fin = i + k;
                for(int j = init; j<=fin; j++) {
                    sum += nums[j];
                }
                int avg = sum/(2*k + 1);
                ans[i] = avg;
            };
        };
        return ans;
    }
};

// Prefix Sum O(2*n) Approach

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return nums;
        vector<int> ans(n, -1);
        if(2*k + 1 > n) return ans;
        vector<long long> cumsum(n, 0);
        cumsum[0] = nums[0];
        for(int i = 1; i<n; i++) {
            cumsum[i] = cumsum[i - 1] + nums[i];
        } 
        for(int i = k; i<n-k; i++) {
            int left = i - k;
            int right = i + k;
            long long sum = cumsum[right];
            if(left > 0)
                sum -= cumsum[left - 1];
            int avg = sum/(2*k+1);
            ans[i] = avg;
        };
        return ans;
    }
};