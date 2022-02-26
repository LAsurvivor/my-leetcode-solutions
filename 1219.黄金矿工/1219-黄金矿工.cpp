class Solution {
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

public:    
    int dfs(int i, int j, int sum_, vvi& grid){
        int origin = grid[i][j];
        sum_ += origin;
        grid[i][j] = 0;
        int tmp = sum_;

        auto out_of_edge = [&] (int i, int j){
            return i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size();  
        };
        
        for(int k = 0; k < 4; k++){
            int ti = i + di[k], tj = j + dj[k];
            if(!out_of_edge(ti, tj) && grid[ti][tj])
                sum_ = max(sum_, dfs(ti, tj, tmp, grid));
        }

        grid[i][j] = origin;

        return sum_;
    }
    
    int getMaximumGold(vvi& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    ans = max(ans, dfs(i, j, 0, grid));
                }
            }
        }
        return ans;
    }
};