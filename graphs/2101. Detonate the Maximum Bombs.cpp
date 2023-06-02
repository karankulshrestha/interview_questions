/*
    uname: karankulx
    qname: Detonate the Maximum Bombs
    companies: Google, Microsoft
    qlink: https://leetcode.com/problems/detonate-the-maximum-bombs/description/
*/


// Using DFS;  

class Solution {
public:
    typedef long long ll;
    void dfs(int node, unordered_set<int> & visited, unordered_map<int, vector<int>>& adj) {
        visited.insert(node);
        for(int &it : adj[node]) {
            if(visited.find(it) == visited.end()) {
                dfs(it, visited, adj);
            };
        }

    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) {
                    continue;
                }
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll dist = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

                if(ll(r1*r1) >= dist) {
                    adj[i].push_back(j);
                }
            }
        }
        int result = 0;
        unordered_set<int> visited;
        for(int i = 0; i<n; i++) {
            dfs(i, visited, adj);
            int cnt = visited.size();
            result = max(result, cnt);
            visited.clear();
        }
        return result;
    }
};


// Using BFS

class Solution {
public:
    typedef long long ll;
    int bfs(int node, unordered_map<int, vector<int>>& adj) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(node);
        visited.insert(node);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto & it : adj[v]) {
                if(visited.find(it) == visited.end()) {
                    visited.insert(it);
                    q.push(it);
                }
            }
        }
        return visited.size();
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) {
                    continue;
                }
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll dist = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

                if(ll(r1*r1) >= dist) {
                    adj[i].push_back(j);
                }
            }
        }
        int result = 0;
        for(int i = 0; i<n; i++) {
            int cnt = bfs(i, adj);
            result = max(result, cnt);
        }
        return result;
    }
};