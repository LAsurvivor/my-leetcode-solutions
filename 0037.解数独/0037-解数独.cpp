class Solution {
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
public:
    void solveSudoku(vector<vector<char>>& board) {
        vvi r(9, vector<int>(9, 0));
        vvi c(9, vector<int>(9, 0));
        vvi b(9, vector<int>(9, 0));
        set<pii> vis;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    vis.emplace(pii(i, j));
                    r[i][num-1]++;
                    c[j][num-1]++;
                    b[i/3*3+j/3][num-1]++;
                }
            }
        }

        auto is_valid = [&] (int i, int j, int num, vvi& row, vvi& col, vvi& box) {
            return !(row[i][num-1] || col[j][num-1] || box[i/3*3+j/3][num-1]);
        };

        auto dfs = [&] (auto self, int i, int j, vvi row, vvi col, vvi box){
            // existed at the beginning
            if(vis.count({i, j})){
                if(i == 8 && j == 8) return true;
                else if(j == 8){
                    i += 1;
                    j = 0;
                } else j += 1;

                if(self(self, i, j, row, col, box)) return true;
            }
            // blank at the beginning
            else{
                for(int num = 1; num <= 9; num++){
                    if(is_valid(i, j, num, row, col, box)){
                        vvi tr = row;
                        vvi tc = col;
                        vvi tb = box;

                        tr[i][num-1]++;
                        tc[j][num-1]++;
                        tb[i/3*3+j/3][num-1]++;
                        board[i][j] = '0' + num;

                        int ti, tj;
                        if(i == 8 && j == 8) return true;
                        else if(j == 8){
                            ti = i + 1;
                            tj = 0;
                        } else{
                            ti = i;
                            tj = j + 1;
                        }

                        if(self(self, ti, tj, tr, tc, tb)) return true;
                    }
                }
            }
            return false;
        };

        dfs(dfs, 0, 0, r, c, b);
    }
};