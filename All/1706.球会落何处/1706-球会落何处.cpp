class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();

        for(int start = 0; start < n; start++){
            int flag = 1, j = start;
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 1){
                    if(j == n - 1 || grid[i][j+1] == -1){
                        flag = 0;
                        break;
                    } else j++;
                } else {
                    if(j == 0 || grid[i][j-1] == 1){
                        flag = 0;
                        break;
                    } else j--;
                }
            }
            if(flag) ans.push_back(j);
            else ans.push_back(-1);
        }
        return ans;
    }
};