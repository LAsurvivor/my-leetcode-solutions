class Solution {
public:
    vector<int> getnext(string s){
        vector<int> next(s.size());
        int i = 0, j = -1;
        next[0] = -1;
        while(i < s.size() - 1){
            if(j == -1 || s[i] == s[j]){
                ++i, ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }
    int KMPMatch(string s1, string s2){
        vector<int> next = getnext(s2);
        int i = 0, j = 0, m = s1.size(), n = s2.size();
        while(i < m && j < n){
            if(j == -1 || s1[i] == s2[j]){
                i++; j++;
            } else {
                j = next[j];
            }
        }
        if(j == n) return i - j;
        return -1;
    }

    bool rotateString(string s, string goal) {
        if(s.size() == 0 || s.size() != goal.size()) return false;
        s += s;
        return KMPMatch(s, goal) != -1;
    }
};