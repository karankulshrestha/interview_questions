/*
    uname: karankulx
    qname: Alien Dictionary
    companies: Flipkart, Amazon, Microsoft, OYO Rooms, Walmart, Google
    qlink: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
    rating: Hard
*/

class Solution{
    private:
    vector<int> sorted(int v, vector<vector<int>>& adj) {
        vector<int> indegree(v, 0);
        for(int i = 0; i<v; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            };
        };
        queue<int> q;
        for(int i = 0; i<v; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            };
        };
        vector<int> ord;
        while(!q.empty()) {
            int el = q.front();
            ord.push_back(el);
            q.pop();
            for(auto it : adj[el]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            };
        };
        return ord;
    };
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        for(int i = 0; i<N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for(int j = 0; j<len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                };
            };
        };
        vector<int> ans = sorted(K, adj);
        string a = "";
        for(auto it : ans) {
            a += it + 'a';
        };
        return a;
    }
};