class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++) mp[order[i]] = i;

        auto cmp = [&mp] (char c1, char c2) {
            return !mp.count(c1) || mp[c1] > mp[c2];
        };

        priority_queue<char, vector<char>, decltype(cmp)> q(cmp);

        for(auto& c : s) q.push(c);

        string ans;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};