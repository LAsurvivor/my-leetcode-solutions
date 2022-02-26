class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int box[9][9];
        int temp;

        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                temp = board[i][j] - '0' - 1;

                if(row[i][temp] || col[j][temp] || box[i/3*3+j/3][temp]) return false;
                row[i][temp]++;
                col[j][temp]++;
                box[i/3*3+j/3][temp]++;
            }
        }
        return true;
    }
};