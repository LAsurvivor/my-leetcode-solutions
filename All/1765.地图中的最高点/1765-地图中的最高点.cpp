class Solution {
using pii = pair<int, int>;
using arr = array<int ,3>;
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<arr> q;
        set<pii> vis;
        vector<int> dx{1, -1, 0, 0};
        vector<int> dy{0, 0, 1, -1};

        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j]){
                    q.push({i, j, 0});
                    vis.emplace(pii(i, j));
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto [x, y, h] = q.front();
            q.pop();
            ans[x][y] = h;

            for(int i = 0; i < 4; i++){
                int tmp_x = x + dx[i];
                int tmp_y = y + dy[i];

                if(tmp_x >=0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && !vis.count({tmp_x, tmp_y})){
                    q.push({tmp_x, tmp_y, h+1});
                    vis.emplace(pii(tmp_x, tmp_y));
                }
            }
        }
        return ans;
    }
};