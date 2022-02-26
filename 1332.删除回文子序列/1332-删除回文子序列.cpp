class Solution {
public:
    int removePalindromeSub(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        return r == s? 1 : 2;
    }
};