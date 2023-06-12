/*
    uname: karankulx
    qlink: https://leetcode.com/problems/summary-ranges/description/
    companies: Google, Meta, Netflix
    qname: Summary Ranges
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(long long i = 0; i<nums.size(); i++) {
            const long long init = nums[i];
            while(i + 1 < nums.size() && nums[i] == nums[i + 1] - 1)
                i++;
            const long long fin = nums[i];
            if(init == fin) {
                ans.push_back(to_string(init));
            } else {
                ans.push_back(to_string(init) + "->" + to_string(fin));
            }
        };
        return ans;
    }
};