class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto& i : arr) mp[i]++;
        sort(arr.begin(), arr.end());

        for (auto& i : arr) {
            if (mp[i] == 0) continue;
            mp[i]--;
            if (i < 0) {
                if (i & 1) return false;
                if (mp.count(i / 2) && mp[i/2] > 0) {
                    mp[i/2]--;
                } else return false;
            } else {
                if (mp.count(i * 2) && mp[i*2] > 0) {
                    mp[i*2]--;
                } else return false;
            }
        }
        return true;
    }
};