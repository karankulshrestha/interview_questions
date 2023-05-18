/*
    uname: karankulx
    qname: Minimum Number of Vertices to Reach All Nodes
    Companies: Google
    qlink: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
    Rating: Medium
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for(auto it : edges) {
            graph[it[0]].push_back(it[1]);
        };

        for(int i = 0; i<n; i++) {
            for(auto it : graph[i]) {
                indegree[it]++;
            };
        };
        vector<int> vert;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                vert.push_back(i);
            };
        };
        return vert;
    }
};