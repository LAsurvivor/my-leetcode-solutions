class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();

        vector<vector<int>> vec(vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                vec[i][j] = img[i-1][j-1] + vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1];
            }
        }

        vector<vector<int>> ans(vector<vector<int>>(m, vector<int>(n, 0)));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int t = max(i - 1, 0); int l = max(j - 1, 0);
                int b = min(i + 2, m); int r = min(j + 2, n);
                int cnt = (r - l) * (b - t);
                ans[i][j] = (vec[b][r] - vec[t][r] - vec[b][l] + vec[t][l]) / cnt;
            }
        }

        return ans;
    }
};