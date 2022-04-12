class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans(2);
        ans[0] = 1;
        ans[1] = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int curr = widths[s[i]-'a'];
            if (ans[1] + curr > 100) {
                ans[0]++;
                ans[1] = curr;
            } else {
                ans[1] += curr;
            }
        }

        return ans;
    }
};