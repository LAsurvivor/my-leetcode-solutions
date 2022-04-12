class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto& c : s1) mp[c]++;
        for (auto& c : s2) mp[c]--;
        for (auto& i : mp) if (i.second != 0) return false;
        return true;
    }
};