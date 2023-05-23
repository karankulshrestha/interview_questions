/*
    uname: karankulx
    qname: Shortest path in Undirected Graph having unit distance
    qlink: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
    rating: medium
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        vector<int> distances(N, -1);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        };
        queue<pair<int, int>> q;
        q.push({src, 0});
        distances[src] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto n : adj[node]) {
                if(distances[n] != -1 && distances[n] <= dist + 1) {
                    continue;
                }
                distances[n] = dist + 1;
                q.push({n, dist + 1});
            };
        }
        return distances;
    }
};