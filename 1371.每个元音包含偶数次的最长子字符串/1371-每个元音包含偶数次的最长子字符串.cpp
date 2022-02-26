class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        if(!n) return 0;
        
        vector<int> status_idx(1 << 5, -2);
        status_idx[0] = -1;
        int status = 0, ans = 0;

        for(int i = 0; i < n; i++){
            char tmp = s[i];
            if(tmp == 'a') status ^= 1 << 0;
            if(tmp == 'e') status ^= 1 << 1;
            if(tmp == 'i') status ^= 1 << 2;
            if(tmp == 'o') status ^= 1 << 3;
            if(tmp == 'u') status ^= 1 << 4;

            if(status_idx[status] == -2) {
                status_idx[status] = i;
            } else {
                ans = max(ans, i - status_idx[status]);
            }
        }
        return ans;
    }
};