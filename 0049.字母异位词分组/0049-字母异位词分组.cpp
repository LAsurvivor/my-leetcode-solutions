class Solution {
using ll = long long;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<ll, vector<string>> mp;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

        auto hash = [&primes] (string s) {
            ll h = 1, mod = 1e9 + 7;
            for(auto& i : s){
                h = (h * primes[i-'a']) % mod;
            }
            return h;
        };

        for(auto& i : strs){
            mp[hash(i)].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++)
            ans.push_back(it->second);

        return ans;
    }
};