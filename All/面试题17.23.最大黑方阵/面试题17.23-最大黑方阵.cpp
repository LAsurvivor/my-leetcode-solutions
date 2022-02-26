class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return {};
        if(n == 1) {
            if(matrix[0][0]) return {};
            else return {0, 0, 1};
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
        vector<int> ans{n-1, n-1, 0};

        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(matrix[i][j]){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                } else {
                    dp[i][j][0] = j < n - 1 ? dp[i][j+1][0] + 1 : 1;
                    dp[i][j][1] = i < n - 1 ? dp[i+1][j][1] + 1 : 1;
                }
                int len = min(dp[i][j][0], dp[i][j][1]);
                while(len >= ans[2]){
                    if(dp[i+len-1][j][0] >= len && dp[i][j+len-1][1] >= len){
                        ans = {i, j, len};
                        break;
                    }
                    len--;
                }
            }
        }
        return ans;
    }
};