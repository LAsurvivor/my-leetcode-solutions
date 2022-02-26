class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> ans(2, 0);
        int max_ = -1;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int cnt = 0;
                long long x1 = points[i][0] - points[j][0];
                long long y1 = points[i][1] - points[j][1];

                for(int k = j + 1; k < n; k++){
                    long long x2 = points[i][0] - points[k][0];
                    long long y2 = points[i][1] - points[k][1];
                    if(x1 * y2 == x2 * y1) cnt++;
                }

                if(cnt > max_){
                    max_ = cnt;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};
/*
1
1 1
1
*/