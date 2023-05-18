/*
    uname: karankulx
    qname: Find Eventual Safe States
    qlink: https://leetcode.com/problems/find-eventual-safe-states/description/
    Rating: Medium-Hard
    Companies: FAANG + Bloomberg
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        vector<vector<int>> graph(adj.size());
        vector<int> indegree(adj.size(), 0);
        for(int i = 0; i<adj.size(); i++) {
            for(auto it : adj[i]) {
                graph[it].push_back(i);
                indegree[i]++;
            };
        };
        queue<int> q;
        for(int i = 0; i<graph.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            };
        };

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : graph[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            };
        };
        sort(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    bool checkdfs(vector<vector<int>>& graph, int node, vector<int>& vis, vector<int>& pathdfs, vector<int>& check) {
        vis[node] = 1;
        pathdfs[node] = 1;
        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(checkdfs(graph, it, vis, pathdfs, check)) return true;
            } else if(pathdfs[it]) return true;
        };
        check.push_back(node);
        pathdfs[node] = 0;
        return false;
    };

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> pathdfs(v, 0);
        vector<int> check;
        for(int i = 0; i<v; i++) {
            if(!vis[i]) {
                checkdfs(graph, i, vis, pathdfs, check);
            };
        };
        sort(check.begin(), check.end());
        return check;
    }
};