class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> pos(n, n), neg(n, n);

        for(int i = 0; i < n; i++){
            if(s[i] == c) pos[i] = 0;
            else if(i > 0) pos[i] = pos[i-1] == n ? n : pos[i-1] + 1;
        }
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == c) neg[i] = 0;
            else if(i < n - 1) neg[i] = neg[i+1] == n ? n : neg[i+1] + 1;
        }
        for(int i = 0; i < n; i++) pos[i] = min(pos[i], neg[i]);
        return pos;
    }
};