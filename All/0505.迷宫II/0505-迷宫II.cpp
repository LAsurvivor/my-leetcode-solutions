class Solution {
using ai3 = array<int, 3>;
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[start[0]][start[1]] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        queue<ai3> q;
        q.push({start[0], start[1], 0});

        auto out_of_edge = [&] (int x, int y) {
            return x < 0 || y < 0 || x >= m || y >= n;
        };

        while(!q.empty()){
            auto [x, y, step] = q.front();
            q.pop();

            if(x == destination[0] && y == destination[1]) continue;

            for(int i = 0; i < 4; i++){
                int tmp_step = step + 1;
                int tx = x + dx[i], ty = y + dy[i];
                if(out_of_edge(tx, ty) || maze[tx][ty] == 1) continue;

                while(!out_of_edge(tx + dx[i], ty + dy[i]) && maze[tx+dx[i]][ty+dy[i]] == 0){
                    tx += dx[i];
                    ty += dy[i];
                    tmp_step++;
                }

                if(vis[tx][ty] == 0 || tmp_step < vis[tx][ty] - 1){
                    vis[tx][ty] = tmp_step + 1;
                    q.push({tx, ty, tmp_step});
                }
            }
        }
        return vis[destination[0]][destination[1]] - 1;
    }
};