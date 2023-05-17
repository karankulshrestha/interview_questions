/*
    uname: karankulx
    qname: Course Schedule 1
    qlink: https://leetcode.com/problems/course-schedule-ii/description/
    topic: topological sort
    companies: FANG + Salesforce + Samsung
    rating: medium - hard
*/


class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        };
        for(int i = 0; i<n; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            };
        };

        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        };
        vector<int> patt;
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            patt.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            };
        };
        if(n == cnt) return patt;
        return {};    
    }
};