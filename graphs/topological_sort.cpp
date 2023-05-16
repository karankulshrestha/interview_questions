/*
    uname: karankulx
    companies: Microsoft, Google
    rating: Medium-Hard
    qlink: https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    name: Topological sort
*/


// DFS Approach

class Solution
{
	public:
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> indegree(v, 0);
	    for(int i = 0; i<v; i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++;
	        };
	    };
	    queue<int> q;
	    for(int i = 0; i<v; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        };
	    };
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            };
	        };
	    };
	    return topo;
    }
}


// DFS Approach

class Solution
{
    private:
    void dfs(vector<int>& vis, vector<int> adj[], int node, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(vis, adj, it, st);
            };
        };
        st.push(node);
    };
    
	public:
	//using DFS
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    stack<int> st;
	    for(int i = 0; i<V; i++) {
	        if(!vis[i]) {
	            dfs(vis, adj, i, st);
	        };
	    };
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top());
	        st.pop();
	    };
	    return topo;
	}
};