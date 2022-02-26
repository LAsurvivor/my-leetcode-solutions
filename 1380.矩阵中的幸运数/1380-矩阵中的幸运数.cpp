class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, INT_MAX), col(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[i][j];
                if(tmp < row[i]) row[i] = tmp;
                if(tmp > col[j]) col[j] = tmp;
            }
        }

        vector<int> ans;
        for(auto& i : row){
            for(auto& j : col){
                if(i == j) ans.push_back(i);
            }
        }
        return ans;
    }
};