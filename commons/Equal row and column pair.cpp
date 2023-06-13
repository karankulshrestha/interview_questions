/*
    uname: karankulx
    qlink: https://leetcode.com/problems/equal-row-and-column-pairs/description/
    qname: Equal Row and Column Pairs
    companies: Google, Microsoft

*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int n = grid.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            mp[grid[i]]++;
        }
        
        for(int i = 0; i<n; i++) {
            vector<int> col;
            for(int j = 0; j<n; j++) {
                col.push_back(grid[j][i]);
            }
            cnt += mp[col];
        }
        return cnt;
    }
};