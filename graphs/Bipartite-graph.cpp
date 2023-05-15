/*
    uname: karankulx
    companies: Samsung, Microsoft
    qlink: https://leetcode.com/problems/is-graph-bipartite/description/
    name: Is Graph Bipartite?
*/


// BFS Approach

class Solution {
public:
    bool bfs(int nde, vector<vector<int>>& graph, int n, vector<int>& color) {
        queue<int> q;
        color[nde] = 0;
        q.push(nde);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto i : graph[node]) {
                if(color[i] == -1) {
                    color[i] = !color[node];
                    q.push(i);
                } else if(color[node] == color[i]) {
                    return false;
                };
            };
        };
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++) {
            if(color[i] == -1) {
                if(!bfs(i, graph, n, color)) {
                    return false;
                };
            };
        };
        return true;
    };
};

// DFS Approach

class Solution {
public:
    bool dfs(int nde, vector<vector<int>>& graph, int n, vector<int>& color) {
        if(color[nde] == -1) color[nde] = 1;
        for(auto i : graph[nde]) {
            if(color[i] == -1) {
                color[i] = !color[nde];
                if(!dfs(i, graph, n, color)) {
                    return false;
                };
            } else if(color[i] == color[nde]) {
                return false;
            };
        };
        return true;
    };

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++) {
            if(!dfs(i, graph, n, color)) {
                return false;
            };
        };
        return true;
    };
};