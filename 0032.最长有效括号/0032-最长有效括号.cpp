class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2) return 0;

        int len = s.size(), ans = 0;
        vector<int> dp(len, 0);

        for(int i = 1; i < len; i++){
            if(s[i] == ')'){
                if(s[i-1] == '(') dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else if(i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + (i - dp[i-1] - 2 >= 0 ? dp[i-dp[i-1]-2] : 0) + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};