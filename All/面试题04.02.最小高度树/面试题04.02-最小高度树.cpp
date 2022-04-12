class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> mp(n);
        vector<int> deg(n);

        for (auto& edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
            deg[edge[0]]++;
            deg[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) q.push(i);
        }

        vector<int> ans;
        int remain = n;
        while (remain > 2) {
            int size = q.size();
            remain -= size;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();

                for (auto& adj : mp[node]) {
                    if (--deg[adj] == 1) q.push(adj);
                }
            }
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};