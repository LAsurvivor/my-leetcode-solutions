/*
[0,0,0,1,1,1,0,1,1,1,1,1,0,0,0],
[1,1,1,1,0,0,0,1,1,0,0,0,1,1,1],
[1,1,1,0,0,1,0,1,1,1,0,0,0,1,1],
[1,1,0,1,0,1,1,0,0,0,1,1,0,1,0],
[1,1,1,1,0,0,0,1,1,1,0,0,0,1,1],
[1,0,1,1,0,0,1,1,1,1,1,1,0,0,0],
[0,1,0,0,1,1,1,1,0,0,1,1,1,0,0],
[0,0,1,0,0,0,0,1,1,0,0,1,0,0,0],
[1,0,1,0,0,1,0,0,0,0,0,0,1,0,1],
[1,1,1,0,1,0,1,0,1,1,1,0,0,1,0]]
*/
class Solution {
using pii = pair<int, int>;
using ll = long long;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};


        auto out_of_edge = [&] (int x, int y) {
            return x < 0 || y < 0 || x >= m || y >= n;
        };

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    int cnt = 0, flag = 1;
                    queue<pii> q;
                    q.push({i, j});

                    // bfs
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        if(grid[x][y] == 0) continue;
                        grid[x][y] = 0;
                        cnt++;

                        for(int k = 0; k < 4; k++){
                            int tx = x + dx[k], ty = y + dy[k];

                            if(out_of_edge(tx, ty)){
                                flag = 0;
                                continue;
                            }

                            if(grid[tx][ty]) q.push({tx, ty});
                        }
                    }

                    if(flag) ans += cnt;
                }
            }
        }
        return ans;
    }
};