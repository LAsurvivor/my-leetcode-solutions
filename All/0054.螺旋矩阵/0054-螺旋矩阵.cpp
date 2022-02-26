class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int i = 0, j = 0;
        int step_i = matrix.size(), step_j = matrix[0].size() - 1;
        
        for(int step = 0; step < step_j; step++) ans.push_back(matrix[i][j++]);
        step_j++;
        
        while(1){
            // down
            if(--step_i == 0) break;
            for(int step = 0; step < step_i; step++) ans.push_back(matrix[i++][j]);
            // left
            if(--step_j == 0) break;
            for(int step = 0; step < step_j; step++) ans.push_back(matrix[i][j--]);
            // up
            if(--step_i == 0) break;
            for(int step = 0; step < step_i; step++) ans.push_back(matrix[i--][j]);
            // right
            if(--step_j == 0) break;
            for(int step = 0; step < step_j; step++) ans.push_back(matrix[i][j++]);
        }
        ans.push_back(matrix[i][j]);
        return ans;
    }
};