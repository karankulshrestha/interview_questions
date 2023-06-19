/*
    uname: karankulx
    qname: Find the highest altitude
    qlink: https://leetcode.com/problems/find-the-highest-altitude/description/
    companies: Google, Netflix
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alt(n + 1);
        alt[0] = 0;
        for(int i = 0; i<gain.size(); i++) {
            int temp = alt[i] + gain[i];
            alt[i + 1] = temp;
        };
        sort(alt.begin(), alt.end());
        return alt[gain.size()];
    }
};