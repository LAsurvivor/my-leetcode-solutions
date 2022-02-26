class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < grid[0].size(); j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for(int j = 0; j < grid[0].size(); j++){
            int cnt = 0;
            for(int i = 0; i < grid.size(); i++){
                cnt += grid[i][j];
            }
            if(cnt * 2 < grid.size()){
                for(int i = 0; i < grid.size(); i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]) ans += pow(2, grid[0].size()-j-1);
            }            
        }

        return ans;
    }
};