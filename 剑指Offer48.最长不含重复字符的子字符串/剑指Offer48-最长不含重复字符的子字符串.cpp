class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> mp;
        int i = -1, ans = 0;

        for(int j = 0; j < s.size(); j++){
            if(mp.count(s[j])){
                i = max(i, mp[s[j]]);
            }
            mp[s[j]] = j;
            ans = max(ans, j - i);
        }
        return ans;
    }
};