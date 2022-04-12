class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;

        int ans = 0;
        for (auto& i : time) {
            if (i % 60 == 0)
                ans += mp[0];
            else if (mp.count(60 - i % 60)) 
                ans += mp[60-i%60];
            mp[i%60]++;
        }
        return ans;
    }
};