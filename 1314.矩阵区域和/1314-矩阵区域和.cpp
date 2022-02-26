class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // convolution ???
        // int m = mat.size(), n = mat[0].size();
        // vector<vector<int>> ans(m, vector<int>(n, 0));
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         int s = 0;
        //         for(int r = i - k; r <= i + k; r++){
        //             for(int c = j - k; c <= j + k; c++){
        //                 if(r < 0 || c < 0 || r >= m || c >= n) continue;
        //                 s += mat[r][c];
        //             }
        //         }
        //         ans[i][j] = s;
        //     }
        // }
        // return ans;

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = mat[i-1][j-1] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int t = i - k > 0 ? i - k - 1 : 0;
                int b = i + k <= m ? i + k : m;
                int l = j - k > 0 ? j - k - 1 : 0;
                int r = j + k <= n ? j + k : n;
                mat[i-1][j-1] = prefix[b][r] + prefix[t][l] - prefix[t][r] - prefix[b][l];
            }
        }
        return mat;
    }
};