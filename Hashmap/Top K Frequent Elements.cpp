/*
    uname: karankulx
    companies: Amazon
    qlink: https://leetcode.com/problems/top-k-frequent-elements/description/
    name: Top K Frequent Elements
    rating: easy
*/

class Solution {
public:
    bool comp(pair<char,int> a, pair<char,int> b) {
        return a.second < b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<int, int> mp;
        vector<int> ans;
        vector<pair<int, int>> temp(mp.begin(), mp.end()); 
        sort(temp.begin(), temp.end(), comp);
        for(auto i : nums) {
            mp[i]++;
        };
        int cnt = k;
        for(auto it = mp.cbegin(); it != mp.cend(); ++it)
        {
            if(cnt == 0) {
                return ans;
            }
            ans.push_back(it->first);
            cnt--;
        }
        return ans;
    }
};