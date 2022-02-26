/*
0 0 0 1 0 1
1 0 0 0 1 0
0 0 0 0 0 1
0 0 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 0
*/
class Solution {
using pii = pair<int, int>;
using ll = long long;
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        
        hash<ll> h;
        auto custom_hash = [&h] (pii p) {
            return h(((ll)p.first << 32) + p.second);
        };

        unordered_map<int, int> row, col, left, right;
        unordered_set<pii, decltype(custom_hash)> st(0, custom_hash);

        for(auto& lamp : lamps){
            int x = lamp[0], y = lamp[1];
            if(st.count({x, y})) continue;

            if(row.count(x)) row[x]++;
            else row[x] = 1;
            
            if(col.count(y)) col[y]++;
            else col[y] = 1;

            if(left.count(x-y)) left[x-y]++;
            else left[x-y] = 1;

            if(right.count(x+y)) right[x+y]++;
            else right[x+y] = 1;

            st.insert({x, y});
        }

        auto out_of_edge = [&n] (int& x, int& y) {
            return x < 0 || y < 0 || x >= n || y >= n;
        };

        auto is_lit = [&] (vector<int>& q) {
            int x = q[0], y = q[1];
            
            if(row.count(x) || col.count(y) || left.count(x-y) || right.count(x+y)) {
                for(int i = 0; i < 9; i++){
                    int tx = x + dx[i], ty = y + dy[i];

                    if(out_of_edge(tx, ty)) continue;

                    if(st.count({tx, ty})){
                        st.erase({tx, ty});
                        if(row[tx]-- == 1) row.erase(tx);
                        if(col[ty]-- == 1) col.erase(ty);
                        if(left[tx-ty]-- == 1) left.erase(tx-ty);
                        if(right[tx+ty]-- == 1) right.erase(tx+ty);
                    }
                }
                return 1;
            } else return 0;            
        };


        vector<int> ans;
        for(auto& q : queries) ans.push_back(is_lit(q));
        return ans;
    }
};