/*
    uname: karankulx;
    qname: Detect cycle in directed graph
    qlink: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    rating: Medium - Difficult
    Companies: FANG companies + SalesForce

*/

// Detect cycle in a directed graph using DFS

class Solution {
  private:
  bool dfs(vector<int>& vis, vector<int>& dfsvis, vector<int> adj[], int node) {
      vis[node] = 1;
      dfsvis[node] = 1;
      for(auto it : adj[node]) {
          if(!vis[it]) {
              if(dfs(vis, dfsvis, adj, it)) return true;
          } else if(dfsvis[it]) {
              return true;
          };
      };
      dfsvis[node] = 0;
      return false;
  };
  
  public:
    bool isCyclic(int v, vector<int> adj[]) {
       vector<int> vis(v, 0);
       vector<int> dfsvis(v, 0);
       for(int i = 0; i<v; i++) {
           if(!vis[i]) {
               if(dfs(vis, dfsvis, adj, i)) return true;
           }
       };
       return false;
    }
};

// Detect cycle in directed graph using bfs and Kahn's Algorithm

class Solution {
  public:
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> indegree(v, 0);
        for(int i = 0; i<v; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            };
        };
        queue<int> q;
        for(int i = 0; i<v; i++) {
            if(indegree[i] == 0) q.push(i);
        };
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            };
        };
        if(v == cnt) return false;
        return true;
    };
};