/*
    uname: karankulx
    qname: Shortest Path in Binary Matrix
    qlink: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
    companies: Google, Meta, Microsoft, Amazon
    Dikstra Algorithm Method
*/

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        ans[0][0] = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            auto node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

            for(int i = 0; i<8; i++) {
                int x_ = x + drow[i];
                int y_ = y + dcol[i];
                int dist = 1;

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 0 && d + dist < ans[x_][y_]) {
                    pq.push({dist + d, {x_, y_}});
                    ans[x_][y_] = d + dist;
                }
            };
        };
        if(ans[m - 1][n - 1] == INT_MAX) return -1;
        return ans[m - 1][n - 1] + 1;
    }
};